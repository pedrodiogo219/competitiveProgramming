import numpy as np


def fib(n):
    if n == 0: return 0
    if n == 1: return 1

    f = np.array( [ [1],
                    [0] ] )

    base = np.array( [ [1, 1],
                       [1, 0] ] )

    return expo(base, n-1).dot(f)[0][0]


def expo(base, n):
    if n == 1: return base
    if n%2 == 0:
        nova_base = base.dot(base) #base = base^2
        novo_n = int(n/2)
        return expo(nova_base, novo_n)

    if n%2 == 1:
        nova_base = base.dot(base)
        novo_n = int( (n-1)/2 )
        return base.dot( expo(nova_base, novo_n) ) # base * expo(nova_base, novo_n)
