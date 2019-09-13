#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(ll mid, ll x){
  ll ans = 0LL;
  ll cnt = 1LL;
  ll i = 10LL;
  for (i = 10LL; i<=mid; i *= 10LL){
    if(x < i){
      ans += ((i-x) * cnt);
      x = i;
    }
    cnt++;
  }
  ans += ((mid - x + 1LL)*cnt);
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while (t-- > 0){
    ll n, x;
    scanf("%lld %lld", &n, &x);
    ll lo = x, hi = 100000000000000000LL, ans = -1;
    while (lo <= hi){
      ll mid = (lo + hi) >> 1;
      ll aux = check(mid, x);
      if(aux == n){
        ans = mid;
        break;
      }
      else {
        if(aux < n) lo = mid+1;
        else hi = mid-1;
      }
    }
    if(ans != -1) ans -= (x-1);
    printf("%lld\n", ans);
  }
}
