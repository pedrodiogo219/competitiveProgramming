from math import sin, acos, cos

n, x = list(map(float, input().split()))

pi = acos(-1)
ang = ((360.0/n)/2.0)
ang = (pi * ang) / 180.0
r = ((x/2.0) / sin(ang))

A = pi * r * r
print(A)
