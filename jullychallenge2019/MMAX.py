def fast_expo(base, exp, n):
    if exp == 0:
        return 1
    if exp == 1:
        return (base%n)

    result = (fast_expo( (base*base)%n , exp//2, n )) % n
    if exp%2 != 0:
        result = ((result%n) * (base%n))%n
    return result


t = int(input())
while t > 0:
  t-= 1
  n = int(input())
  k = input().split()
  KmodN = 0
  i = 0

  k.reverse()
  for ele in k:
      KmodN += ((int(ele) % n) * fast_expo(10, i, n))%n
      i+=1

  a, b = KmodN, n-KmodN
  if a > b: a, b = b, a
  ans = 2*a
  if a == b:
      ans -=1

  #print('my ans: ', end="")
  if ans == 0:
      print("0")
  else:
      print(f'{ans}')
