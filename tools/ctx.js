// node ctx.js <regex> <width> <max> files...  -> prints match with context
const fs=require('fs');const [,,pat,w,max,...files]=process.argv;const W=+w,M=+max;
for(const f of files){const t=fs.readFileSync(f,'utf8');const re=new RegExp(pat,'gi');let m,n=0,cnt=0;
 while((m=re.exec(t))){cnt++; if(n<M){n++;console.log(`[${f.split('.webpack/')[1]||f}@${m.index}] `+t.slice(Math.max(0,m.index-W),m.index+m[0].length+W).replace(/\s+/g,' '));}}
 if(cnt) console.log(`== ${f.split('.webpack/')[1]||f}: ${cnt} hits`);}
