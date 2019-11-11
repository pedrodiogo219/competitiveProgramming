n = int(input())

sum = 0
for i in range(1, n+1):
  sum+= i*(i-1)

sum = float(sum)
n = float(n)

print(sum / n)
