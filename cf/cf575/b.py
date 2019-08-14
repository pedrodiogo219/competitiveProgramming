import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register
def write():
  sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


t = int(input())
while t > 0:
    t-=1
    n, k = list(map(int, input().split()))
    v = list(map(int, input().split()))

    cont = 0
    impares = 0
    ans = []
    for i in range(len(v)):
        if v[i] % 2!=0:
            impares+=1
            ans.append(i+1)

    if impares < k:
        print("NO")
    else:
        impares-=k
        if impares % 2 != 0:
            print("NO")
        else:
            print("YES")
            for i in range(k-1):
                print(f"{ans[i]}", end=" ")
            print(f"{n}")
