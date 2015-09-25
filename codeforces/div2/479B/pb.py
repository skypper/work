n, k = map(int, input().split())
t, o = [], []
for i, h in enumerate(map(int, input().split())):
    t.append([h, i + 1])
for i in range(k):
    t.sort()
    if t[0][0] >= t[-1][0] - 1:
        break
    t[0][0] += 1
    t[-1][0] -= 1
    o.append((t[-1][1], t[0][1]))
t.sort()
print(t[-1][0] - t[0][0], len(o))
for oi in o:
    print(oi[0], oi[1])
