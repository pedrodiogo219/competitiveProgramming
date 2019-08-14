#include<bits/stdc++.h>
using namespace std;



int main(){

  int t; scanf("%d", &t);
  while(t--){
    int n; scanf("%d", &n);
    std::vector<int> v(n+5, 0);
    std::vector<int> z(n+5, 0);
    int aux;
    for(int i = 0; i < n; i++){
      scanf("%d", &aux);
      v[aux]+=1;
    }

    for(int i= 0; i < v.size(); i++){
      z[ v[i] ]++;
    }

    long long int soma = 0, atual=0;
    for(int i = z.size()-1; i>=0; i-- ){
      atual+=z[i];
      if(atual>0){
        soma+=i;
        atual--;
      }
    }

    printf("%lld\n", soma);

  }
}
