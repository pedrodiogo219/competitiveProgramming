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

def main():
  n, m = list(map(int, input().split()))
  coins = list(map(int, input().split()))
  ans = 0
  coins.sort()
  for coin in reversed(coins):
    ans += m // coin
    m %= coin
  print(ans if m == 0 else -1)
  return 0

main()