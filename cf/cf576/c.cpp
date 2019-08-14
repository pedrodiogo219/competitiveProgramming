#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef long long ll;
typedef pair<int, long long> ii;
#define f first
#define s second

int n, m, d;
int vet[400100], acc[400100];
vector<ii> compress;

int main(){

  scanf("%d %d", &n, &d);
  for(int i = 0; i < n ; i++){
    scanf("%d", &vet[i]);
  }
  vet[n] = -1;

  sort(vet, vet+n);
  int cont = 1;

  for(int i = 1; i <=n; i++){
    if(vet[i] != vet[i-1]){
      compress.push_back( {vet[i-1], cont} );
      cont = 0;
    }
    cont++;
  }

  acc[0] = 0;
  int total = 0;
  for(int i = 0; i < compress.size(); i++){
    acc[i+1] = acc[i] + compress[i].s;
    total+=compress[i].s;
  }

  // for(int i = 0; i <= compress.size(); i++){
  //   printf("%d ", acc[i]);
  // }printf("\n");

  int distintos = compress.size();

  d*=8;
  int k = d/n;
  debug(k);

  int ans = 1;
  int mid, lo = 0, hi = distintos;
  while(lo<=hi){
    mid = (lo+hi)/2;

    if(32 - __builtin_clz(mid) - (__builtin_popcount(mid) == 1) <= k){
      ans = mid;
      lo = mid+1;
    }
    else{
      hi = mid-1;
    }
  }

  int janela = ans;
  debug(janela);
  ans = 10000000;
  for(int i = 0; i+janela-1 < compress.size(); i++){
    debug(i);
    debug(total - acc[i+janela] + acc[i]);
    ans = min(ans, total - acc[i+janela] + acc[i]);
  }

  printf("%d\n", ans);
}
