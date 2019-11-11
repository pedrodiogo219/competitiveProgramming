#include<bits/stdc++.h>
using namespace std;

int vet[1000];
int main(){
  int t; scanf("%d", &t);
  while(t--){
    int n; scanf("%d", &n);
    for(int i=0; i<n*4; i++){
      scanf("%d", &vet[i]);
    }

    sort(vet, vet+(4*n));

    n*=4;
    int valor = 0;
    if(vet[0] != vet[1] || vet[n-1] != vet[n-2]){
      puts("NO");
      continue;
    }

    valor = vet[0] * vet[n-1];
    // printf("valor: %d\n", valor);
    bool flag = false;
    for(int i = 0; i < n/4; i++){
      if(vet[2*i]!=vet[2*i+1] || vet[n - 2*i - 1] != vet[n - 2*i - 2] || vet[2*i]*vet[n - 2*i - 1] != valor){
        puts("NO");
        flag = true;
        break;
      }
    }

    if(!flag){
      puts("YES");
    }

  }
}
