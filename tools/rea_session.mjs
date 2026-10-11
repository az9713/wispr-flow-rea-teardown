// rea_session.mjs - keep one REA MCP server (and its Ghidra session) alive; serve tool calls from a folder queue.
// Needs GHIDRA_INSTALL_DIR and JAVA_HOME in the environment, and rea-agents 6.3.0 installed globally with npm.
// Drop q/<name>.json = {"tool":"...","args":{...}}; the reply lands in out/<name>.json. Log in session.log.
import { spawn } from 'node:child_process';
import fs from 'node:fs';
import path from 'node:path';

const dir = path.dirname(new URL(import.meta.url).pathname.replace(/^\/(\w:)/, '$1'));
const q = path.join(dir, 'q'), out = path.join(dir, 'out');
fs.mkdirSync(q, { recursive: true }); fs.mkdirSync(out, { recursive: true });
const log = (m) => fs.appendFileSync(path.join(dir, 'session.log'), `${new Date().toISOString()} ${m}\n`);

const srv = spawn(process.execPath, [path.join(process.env.APPDATA, 'npm', 'node_modules', 'rea-agents', 'scripts', 'rea.mjs'), '--mcp'], {
  env: { ...process.env,
    REA_ANALYSIS_PROVIDER: 'ghidra',
    REA_GHIDRA_STARTUP_TIMEOUT_MS: '10800000' },  // default 330000 is too short: the 20 MB helper took 1,310 s
  stdio: ['pipe', 'pipe', 'pipe'] });
log(`server pid ${srv.pid}`);
fs.writeFileSync(path.join(dir, 'server.pid'), String(srv.pid));
srv.stderr.on('data', (d) => fs.appendFileSync(path.join(dir, 'server.err'), d));
srv.on('exit', (c) => { log(`server exit ${c}`); process.exit(1); });

let id = 0, buf = '';
const pending = new Map();
srv.stdout.on('data', (d) => {
  buf += d;
  let i;
  while ((i = buf.indexOf('\n')) >= 0) {
    const line = buf.slice(0, i); buf = buf.slice(i + 1);
    if (!line.trim()) continue;
    let msg; try { msg = JSON.parse(line); } catch { log(`non-json: ${line.slice(0, 200)}`); continue; }
    if (msg.id != null && pending.has(msg.id)) { pending.get(msg.id)(msg); pending.delete(msg.id); }
  }
});
const rpc = (method, params) => new Promise((res) => {
  const n = ++id; pending.set(n, res);
  srv.stdin.write(JSON.stringify({ jsonrpc: '2.0', id: n, method, params }) + '\n');
});

await rpc('initialize', { protocolVersion: '2025-06-18', capabilities: {}, clientInfo: { name: 'rea-session', version: '1' } });
srv.stdin.write(JSON.stringify({ jsonrpc: '2.0', method: 'notifications/initialized' }) + '\n');
fs.writeFileSync(path.join(out, '_tools.json'), JSON.stringify((await rpc('tools/list', {})).result, null, 1));
log('ready');

let busy = false;
setInterval(async () => {
  if (busy) return;
  const f = fs.readdirSync(q).filter((n) => n.endsWith('.json')).sort()[0];
  if (!f) return;
  busy = true;
  let req;
  try { req = JSON.parse(fs.readFileSync(path.join(q, f), 'utf8')); }
  catch (e) { log(`bad ${f}: ${e.message}`); fs.renameSync(path.join(q, f), path.join(out, f + '.bad')); busy = false; return; }
  fs.unlinkSync(path.join(q, f));
  const t0 = Date.now(); log(`start ${f} ${req.tool}`);
  const r = await rpc('tools/call', { name: req.tool, arguments: req.args || {} });
  fs.writeFileSync(path.join(out, f), JSON.stringify(r, null, 1));
  log(`done ${f} ${((Date.now() - t0) / 1000).toFixed(1)}s`);
  busy = false;
}, 1000);
