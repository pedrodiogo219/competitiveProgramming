# ~ <template>

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

# ~ </template>

def solve(v):
  v.sort()
  ans = 1
  for i in range(1, len(v)):
    if v[i] != v[i - 1]:
      ans += 1
  return ans

def main():
  n, m = list(map(int, input().split()))
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))
  kappa = solve(a)
  keepo = solve(b)
  if kappa > keepo:
    print('Hadonaro')
  elif keepo > kappa:
    print('Bolsohad')
  else:
    print('Empate')

main()