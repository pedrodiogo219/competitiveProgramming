def sieve_of_eratosthene(N):
    # Cria-se uma lista referente a todos os inteiros entre 0 e N:
    A = [True] * (N+1)
    # Define os números 0 e 1 como não primos:
    A[0] = A[1] = False
    # Percorra a lista até encontrar o primeiro número primo:
    for value, prime in enumerate(A):
        # O número é primo?
        if prime:
            # Retorna o número primo:
            yield value
            # Remova da lista todos os múltiplos do número enontrado:
            for i in range(value**2, N+1, value):
                A[i] = False

def fatora(x):
    global primes
    if x == 1:
        return [1]
    for p in primes:
        if p*p > x:
            break
        if x%p == 0:
            while x%p == 0:
                x=int(x/p)

            fatores = fatora(x)
            fatores.append(p)
            return fatores

    fatores = [x]
    return fatores

def main():
    global primes
    primes = list(sieve_of_eratosthene(100000))
    while True :
        P = int(input())
        if P == 0: break

        dif1 = (99991**2) % P
        fatores1 = fatora(99991**2 - dif1)
        print(f'{fatores1}   {99991**2-dif1}')
        ultimo_possivel = fatores1[0]
        dif2 = (ultimo_possivel**2) % P
        fatores2 = fatora(ultimo_possivel**2 - dif2)
        print(f'{fatores2}   {ultimo_possivel**2 - dif2}')

        colisoes = []
        for ele in fatores1:
            if ele in fatores2:
                colisoes.append(ele)
        print(f"colisoes: {len(colisoes)}    {colisoes}")












main()
