#include<bits/stdc++.h>
using namespace std;

int vet[1000], n;

int main(){
  int t; scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &vet[i]);
    }

    bool flag = false;
    bool essa = true, outra = true;

    for(int i = 0; i < n; i++){
      if(vet[i] == 1){
        for(int a = 0; a< n; a++){
          // printf("%d ", vet[ (i+a+n)%n ]);
          if(vet[ (i+a+n)%n ] != a+1){
            essa= false;

          }
          if(vet[ (i-a+n)%n ] != a+1){
            outra = false;

          }
        }
        break;
      }
    }



    if(essa || outra) printf("YES\n");
    else printf("NO\n");
  }
}
