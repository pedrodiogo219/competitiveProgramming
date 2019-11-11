#include<bits/stdc++.h>
using namespace std;

struct intervalo{
  long long int a, b;
  long long int x;

  intervalo(){
  }

  intervalo(long long _a, long long _b, long long _x){
    a = _a;
    b = _b;
    x = _x;
  }

  const inline bool operator < (intervalo aux){
    return a < aux.a;
  }

  long long size(){
    return b - a +1;
  }
};

vector<intervalo> vet;

int main(){
  int t; scanf("%d", &t);
  int n, k;
  while(t-- > 0){
    scanf("%d %d", &n, &k);
    int a, b, x;
    for(int i = 0; i < n; i++){
      scanf("%d %d %d", &a, &b, &x);
      if(b-a+1 > k){
        vet.push_back( intervalo(a, a+k, x) );
        vet.push_back( intervalo(b-k, b, x) );
      }
      else vet.push_back( intervalo(a, b, x) );
    }
    n = vet.size();
    sort(vet.begin(), vet.end());

    deque<intervalo> dk;

    long long ans = 0;

    long long sz = 0, soma = 0;
    for(int i = 0; i < n; i++){
      if(dk.empty() || vet[i].size() + sz <= k){
        dk.push_back( vet[i] );
        sz += vet[i].size();
        soma += vet[i].size() * vet[i].x;

        ans = max(ans, soma);
      }

      if(!dk.empty()){
        intervalo inicio = dk.front();
        intervalo final = dk.back();

        if(sz == k){

        }

      }

    }

    vet.clear();
  }
}
