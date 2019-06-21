n = input()
v = input().split()
for i in range(0, len(v)):
    v[i] = int(v[i])

for i in range(0, len(v)):
    if abs(v[i]) <  abs(-v[i]-1):
        v[i] = -v[i] - 1

v.sort(key=abs)

pos = 1
for i in range(0, len(v)-1):
    if v[i] < 0:
        pos *= -1


if pos * v[len(v)-1] < 0:
    v[len(v)-1] = -v[len(v)-1]-1



for i in range(0, len(v)):
    if i != 0: print(" ", end='')
    print(v[i], end="")
print()
