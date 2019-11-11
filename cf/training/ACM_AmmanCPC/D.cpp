#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; scanf("%d", &t);
  long long n, m;
  while(t-- > 0){
    scanf("%lld %lld", &n, &m);
    if(n > m) swap(n, m);
    if(m & 1){
      printf("%lld\n", ((m/2LL) + 1LL)*n );
    }
    else{
      long long ans = ((m/2LL) * (n/2LL)) + (((m/2LL) + 1LL)*(n/2LL));
      if(n&1) ans += m/2LL;

      printf("%lld\n", ans);
    }
  }
}
