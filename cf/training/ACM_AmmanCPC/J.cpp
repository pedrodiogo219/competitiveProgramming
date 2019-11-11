#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, v, x;


ll solve() {
  for(int i = 63; i >= 0; i--){
    if( (v & (1LL<<i))   ){
      x = v;
      x ^= (1LL << i);
      for(int j=i-1; j >= 0; j--){
        x |= (1LL << j);
      }
      break;
    }
  }
  return min(x,b);
}

int main() {
  int t;

  scanf("%d", &t);

  while(t--) {
    scanf("%lld %lld %lld", &a, &b, &v);

    if(v >= b) printf("%lld\n", b-a+1);
    else if(v < a) printf("0\n");
    else {
      printf("%lld\n", solve()-a+1);
    }
  }
}
