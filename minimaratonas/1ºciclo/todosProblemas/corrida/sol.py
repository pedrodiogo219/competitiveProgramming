n = int(input())
v = input().split()

for i in range(0, len(v)):
    v[i] = int(v[i])
    

l, r = input().split()
l = int(l)
r = int(r)

menor = v[l-1]
maior = v[l-1]

for i in range(l-1, r):
    menor = min(menor, v[i])
    maior = max(maior, v[i])
    
    
print(maior-menor)    

