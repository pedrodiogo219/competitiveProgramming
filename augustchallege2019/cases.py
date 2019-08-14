from math import log10, ceil, floor

t = 100
print( int((t*(t-1))/2) )
for i in range(1, t+1):
  for j in range(1, i):
      x = floor(log10(j)) + 1
      x = int(x)
      print(f"{x} {j}")
      x = floor(log10(i)) + 1
      x = int(x)
      print(f"{x} {i}")
