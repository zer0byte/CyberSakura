from ptrlib import *
from asm import assemble

sock = Socket("13.48.59.61", 50000)
#sock = Process(["python", "hjarnknull.py"])

# data[1XX] = XX
codeList = assemble([
    "iseq data[999]=data[999] { call code[2] }",
    "iseq data[999]=data[999] { call code[1] }",
    "recv data[0]",
    "recv data[1]",
    "recv data[2]",
    "shr data[100], data[101]",
    "shl data[102], data[101]",
    "iseq data[0]=data[100] { call code[1] }",
])
for i, code in enumerate(codeList):
    print(code)
    sock.sendlineafter(str(i)+": ", code)

sock.interactive()