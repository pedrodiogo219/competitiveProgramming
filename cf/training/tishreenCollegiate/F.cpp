#include<bits/stdc++.h>
using namespace std;


int vet[15];

int main(){
  int t; scanf("%d", &t);
  int n;
  while(t--){
    int n; scanf("%d", &n);

    int f, ans = -1;
    scanf("%d", &f);
    vet[0] = f;
    if(f!=1) ans = 1;
    for(int i = 1; i <= n-2; i++){
      scanf("%d", &vet[i]);
      if(vet[i] != vet[i-1]+1) ans = vet[i-1] + 1;
    }
    if(ans == -1) ans = n;

    printf("%d\n", ans);

  }
}
