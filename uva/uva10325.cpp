//The Lotery -- inclusion-exclusion
#include<bits/stdc++.h>
using namespace std;

long long int p[20];


int main(){
  long long int m, n;
  while(scanf("%lld %lld", &n, &m)!=EOF){
    for(int i = 0; i < m; i++){
      scanf("%lld", &p[i]);
    }

    long long ans = 0;

    for(long long mask = 1LL; mask < (1LL << m); mask++){
      int cont = 0;
      long long mult = 1LL;
      // printf("fatores considerados: \n");
      for(int i = 0; i < m; i++){
        if(mask & (1LL << i)){
          cont++;
          mult= (mult*p[i])/__gcd(mult, p[i]) ;
          // printf("%lld\n", novo[i]);
        }
      }
      long long parcela = n/mult;
      // printf("parcela: %d\n", parcela);
      if(cont % 2 == 0) ans-=parcela;
      else ans+=parcela;

    }

    printf("%lld\n", n - ans);
  }
}
