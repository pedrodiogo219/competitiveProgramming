t = int(input())
while t>0:
    t-=1
    n = int(input())
    v = list(map(int, input().split()))

    soma = 0
    for e in v:
        soma+=e


    if soma%n == 0 and soma/n in v:
        media = int(soma/n)
        for i in range(0, n):
            if v[i] == media:
                print(i+1)
                break
    else:
        print("Impossible")
