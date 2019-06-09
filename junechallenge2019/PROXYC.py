import math
t = int(input())

while t > 0:
    t-=1
    size = int(input())
    s = input()
    quant = math.ceil(size*3/4.0)
    presencas = int(0)
    possiveis = int(0)
    for d in s:
        if d == 'P': presencas+=1

    for i in range(2, size - 2):
        if s[i] == 'A':
            if (s[i-1] == 'P' or s[i-2] == 'P') and ( s[i+1] == 'P' or s[i+2] == 'P'):
                possiveis+=1

    if quant - presencas <= possiveis:
        print(str(quant-presencas))
    else:
        print("-1")
