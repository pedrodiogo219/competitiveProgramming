#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int main(){
  int t; scanf("%d", &t);
  while(t--){
    ll n, k;
    scanf("%lld %lld", &n, &k);

    if(n >= k){
      printf("%lld\n", k-1LL);
      continue;
    }

    ll a = (n + k - 1LL )%MOD;
    ll b = ( k-n )%MOD;

    if(a%2 == 0) a/=2;
    else b/=2;

    ll p1 = (a * b)%MOD;
    ll p2 = (n%MOD * (k-n)%MOD)%MOD;
    ll p3 = (k-n)%MOD;

    ll res = ceil( (double)(p1 - p2 + p3) / (double)(n-1LL) );
    res = (res%MOD + (k-1LL)%MOD)%MOD;
    printf("%lld\n", res);

  }
}
