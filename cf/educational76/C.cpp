#include<bits/stdc++.h>
using namespace std;



int vet[200100];
int outro[200100];

int main(){
  int t; scanf("%d", &t);

  int n, aux;
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i <= n+10; i++){
      vet[i] = -1;
    }

    int dist = 99999999;
    bool flag = false;
    for(int i = 0; i < n; i++){
      scanf("%d", &aux);
      if(vet[aux] == -1){
        vet[aux] = i;
      }else{
        if(i - vet[aux] < dist){
          dist = i - vet[aux];
          flag = true;
        }
        vet[aux] = i;
      }
    }

    if(!flag){
      printf("-1\n");
    }
    else{
      printf("%d\n", dist + 1);
    }
  }
}
