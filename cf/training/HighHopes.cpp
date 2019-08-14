#include<bits/stdc++.h>
using namespace std;

#define Lim 1000000

bool isPrime[Lim+50];
bool vis[Lim+50];
vector<int> fact[Lim+50];

void crivo(){
  for(int i = 2; i <= Lim; i++){
    if(vis[i]) continue;
    isPrime[i] = true;
    for(int j = i; j <= Lim; j+=i){
      vis[j] = true;
      fact[j].push_back(i);
    }
  }
}

int expo(int b, int e){
  if(e == 0) return 1;
  if(e == 1) return b;

  return expo(b*b, e/2) * (e&1 ? b:1);
}

int phi(int m){
  if(m == 1) return 1;
  if( isPrime[m] ) return m-1;

  int factor = fact[m][0];
  int k = 0;

  while(m % factor == 0){
    m/=factor;
    k++;
  }
  return ( expo(factor, k) - expo(factor, k-1) ) * phi(m);
}


int main(){
  crivo();

  int t; scanf("%d", &t);
  int a, m;
  while(t--){
    scanf("%d %d", &a, &m);
    if(__gcd(a, m) != 1) printf("-1\n");
    else printf("%d\n", phi(m));
  }

}
