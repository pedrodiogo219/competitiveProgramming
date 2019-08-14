q = int(input())

for a in range(q):
    n, k = input().split()
    v = input().split()

    n = int(n)
    k = int(k)

    for i in range(len(v)):
        v[i] = int(v[i])

    max = -1
    min = 1000000000

    for ele in v:
        if ele < min:
            min = ele
        if ele > max:
            max = ele

    if max - k <= min + k:
        print(min+k)
    else:
        print('-1')
