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
      printf("%lld\n", (k-1LL)%MOD);
      continue;
    }

    ll vezes = n-1LL;
    ll comprimento = k - n;
    ll parte = comprimento / vezes;
    ll resto = comprimento % vezes;

    ll soma =
    (
      (
        (
          (
            ((1LL + (parte%MOD))%MOD)*(parte%MOD)
          )%MOD * 500000004
        )%MOD
      )*(vezes%MOD)
    )%MOD;

    soma += ((resto%MOD) * (((parte%MOD)+1LL)%MOD) )%MOD;

    printf("%lld\n",  ((soma%MOD) + (k - 1LL)%MOD )%MOD );

  }
}
