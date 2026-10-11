// minimal asar extractor: node asar.js <asar> <outdir> [filterRegex]
const fs=require('fs'),path=require('path');
const [,,file,out,filt]=process.argv; const re=filt?new RegExp(filt):null;
const fd=fs.openSync(file,'r'); const b=Buffer.alloc(16); fs.readSync(fd,b,0,16,0);
const hsize=b.readUInt32LE(4); const jlen=b.readUInt32LE(12);
const hb=Buffer.alloc(jlen); fs.readSync(fd,hb,0,jlen,16); const header=JSON.parse(hb.toString());
const base=8+hsize; let list=[];
(function walk(n,p){ for(const [k,v] of Object.entries(n.files||{})){ const q=p?p+'/'+k:k; if(v.files) walk(v,q); else list.push([q,v]); } })(header,'');
for(const [q,v] of list){ console.log((v.unpacked?'U ':'  ')+(v.size||0)+'\t'+q);
  if(re && re.test(q) && !v.unpacked && !v.link){ const buf=Buffer.alloc(v.size); fs.readSync(fd,buf,0,v.size,base+Number(v.offset)); const o=path.join(out,q); fs.mkdirSync(path.dirname(o),{recursive:true}); fs.writeFileSync(o,buf);} }
