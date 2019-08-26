inf = 1000000000
t = int(input())
dp = [inf for i in range(1000100)]
while t > 0:
    t-=1
    n, money = input().split()
    money = int(money)
    n = int(n)
    moedas = [int(x) for x in input().split()]

    for i in range(money+10):
        dp[i] = inf
    dp[0] = 0

    for din in range(0, money+1):
        for moeda in moedas:
            if din - moeda >= 0:
                dp[din] = min(dp[din], dp[din-moeda]+1)

    print(dp[money])
