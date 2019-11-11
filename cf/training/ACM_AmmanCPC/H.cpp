#include<bits/stdc++.h>
using namespace std;

int vet[10000];
const int INF = 99999999;
int main(){
  int t; scanf("%d", &t);
  while(t--){

    int n; scanf("%d", &n);

    for(int i = 1; i <= 2*n; i++){
      scanf("%d", &vet[i]);
    }
    int menor = 0;
    for(int i = 1; i <= n; i++){
      menor = max(menor, vet[i] + vet[2*n - i + 1]);
    }

    printf("%d\n", menor);

  }
}
