for n in range(3, 6):
    for k in range(0, 11):
        KmodN = k%n
        #print(f"n: {n}   k:{k}", end="  ")
        v = []
        i = 0
        cont = 0
        x = k//n
        # print(f'x: {x}')
        while i < n and k != (n-i)*(x+1) :
          v.append(x)
          k-=x
          i+=1
          cont+=1
        while i < n:
          i+=1
          v.append(x+1)

        #print(v, end=" ")

        i = 0

        a, b = KmodN, n-KmodN
        if(a > b): a, b = b, a
        ans = a*2
        if b == a:
            ans-=1

        #print('my ans: ', end="")
        if ans == 0:
            print("0")
        else:
            print(f'{ans}')
