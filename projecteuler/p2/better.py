a = 1
b = 2

sum = 0
while b < 4000000:
  sum+=b
  a, b = a+b+ b, a+b + a+b + b

print(sum)
