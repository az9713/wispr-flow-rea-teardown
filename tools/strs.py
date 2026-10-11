# python strs.py <helper.exe> <file.c>... : annotate PTR_DAT_/DAT_ refs that point at .NET string objects.
# A NativeAOT frozen string object is: MethodTable pointer (8 B), length (4 B), UTF-16 chars. So chars start at +0xC.
import re, struct, sys
B = open(sys.argv[1], "rb").read()
pe = struct.unpack_from("<I", B, 0x3C)[0]; n = struct.unpack_from("<H", B, pe + 6)[0]; opt = struct.unpack_from("<H", B, pe + 20)[0]
secs = [struct.unpack_from("<8sIIII", B, pe + 24 + opt + 40 * i) for i in range(n)]
def off(va):
    rva = va - 0x140000000
    for _, vs, vaddr, rs, ro in secs:
        if vaddr <= rva < vaddr + rs: return ro + rva - vaddr
def s(va):
    o = off(va)
    if o is None or o + 12 > len(B): return None
    ln = struct.unpack_from("<i", B, o + 8)[0]
    if not 0 < ln < 400: return None
    t = B[o + 12:o + 12 + 2 * ln].decode("utf-16-le", "replace")
    return t if t.isascii() and t.isprintable() else None
for f in sys.argv[2:]:
    c = open(f).read()
    c = re.sub(r"&?(?:PTR_)?DAT_(1[0-9a-f]{8})", lambda m: m.group(0) + (f'/*"{s(int(m.group(1),16))}"*/' if s(int(m.group(1),16)) else ""), c)
    open(f.replace(".c", ".s.c"), "w").write(c)
