#include<bits/stdc++.h>
using namespace std;

int n;

std::vector<int> v(100100, -1);

int main(){
  scanf("%d", &n);

  int cont = 1;

  for(int i = 2; i <= n; i++){
    if(v[i] == -1){
      v[i] = cont;
      for(int j = i+i; j <= n; j+=i){
        if(v[j] != -1) v[j] = min(v[j], cont);
        else v[j] = cont;
      }

      cont++;
    }
  }


  for(int i=2; i <=n; i++){
    if(i!=2) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
}
