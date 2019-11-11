#include<bits/stdc++.h>
using namespace std;

int respostas[100];
long long int vet[300100];

int main(){
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld", &vet[i]);
  }
  // int n = 10;
  // for(int i = 0; i < n; i++){
  //   vet[i] = i+1;
  // }
  // int n = 4;
  // vet[0] = 1;
  // vet[1] = 2;
  // vet[2] = 9;
  // vet[3] = 10;

  sort(vet, vet+n);

  int L = 0;
  int R = n-1;
  long long int quantD = 1;
  long long int quantE = 1;
  long long sD = vet[R];
  long long sE = vet[L];

  printf("%lld", sD - sE);
  long long ans = sD-sE;

  for(int i = 3; i <= n; i++){
    int pos = -1;

    // printf("\nsE: %d\n", sE);
    // printf("sD: %d\n", sD);
    //
    // printf("quantE: %d\n", quantE);
    // printf("quantD: %d\n", quantD);

    if(quantE < quantD){
      pos = L+1;
      L++;
      // printf("\nparcela: %d\n", (sD - sE + ((quantE-quantD) * vet[pos]) ));
      // printf("vet[pos]: %d\n", vet[pos]);
      ans += (sD - sE + ((quantE-quantD) * vet[pos]) );
      quantE++;
      sE += vet[pos];
    }else{
      pos = R-1;
      R--;
      // printf("parcela: %d\n", (sD - sE + ((quantE-quantD) * vet[pos]) ));
      ans += (sD - sE + ((quantE-quantD) * vet[pos]) );
      quantD++;
      sD += vet[pos];
    }
    printf(" %lld", ans);

  }

  printf("\n");

  // for(int mask = 1; mask < (1<<n); mask++){
  //   int acesos = __builtin_popcount(mask);
  //   if(acesos == 1) continue;
  //
  //   vector<int> v;
  //   for(int i = 0; (1 << i) <= mask; i++){
  //     if( mask & (1 << i) ) v.push_back(vet[i]);
  //   }
  //
  //   int soma = 0;
  //   for(int i = 0; i < v.size(); i++){
  //     for(int j = i+1; j< v.size(); j++){
  //       soma += abs(v[i] - v[j]);
  //     }
  //   }
  //
  //   respostas[acesos] = max(respostas[acesos], soma);
  // }
  //
  // for(int i = 2; i <= n; i++){
  //   if(i>2) printf(" ");
  //   printf("%d", respostas[i]);
  // }
  // printf("\n");

}
