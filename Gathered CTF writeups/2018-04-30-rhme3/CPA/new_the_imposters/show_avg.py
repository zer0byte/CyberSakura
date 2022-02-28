from library import *
from collections import defaultdict

if len(sys.argv) > 2:
    n = int(sys.argv[2])
else:
    n = None

i, o, t = load_npz(sys.argv[1])

t = t[:, 275000:305000]
normalize(t)
align_fft(t, 1000)
t = t[:, :-1000]

if 1:
    t_parts = np.zeros((len(t) * 16, 2000))
    for j, tra in enumerate(t):
        off = 3500
        for k in range(16):
            t_parts[j * 16 + k] = tra[off:off+2000]
            off += 1350
            if k % 4 == 3:
                off += 340

    align_fft(t_parts, 100)
    t = t_parts

if 1:
    t = t[:, 100:1600]
    normalize(t)
    align_fft(t, 200)

    if 0:
        t = t[:, 4500:6500]
        normalize(t)
        align_fft(t, 100)

t_avg = np.zeros((len(t) / 16, 1500))
for j in range(len(t_avg)):
    t_avg[j] = np.mean(t[j*16:j*16+16], axis=0)

t = t_avg

d = defaultdict(list)
for j, inp in enumerate(i):
    inp = "".join(chr(c) for c in inp)
    d[inp].append(j)

tlist = []
for indices in d.values():
    tlist.append(indices)

t1 = t[tlist[0][:12]]
t2 = t[tlist[1][:12]]

show_red_green(t1, t2)
