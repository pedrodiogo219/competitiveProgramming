#include<bits/stdc++.h>
using namespace std;
#define INF 100000

int vis[1100];
int vet[10000], dist[1000];
int main(){
  int t; scanf("%d", &t);
  while(t--){

    int n, me = INF, ma = -INF;
    scanf("%d", &n);
    for(int i = 0; i < 4*n; i++){
      scanf("%d", &vet[i]);
      me = min(me, vet[i]);
      ma = max(ma, vet[i]);
      vis[vet[i]]++;
    }

    sort(vet, vet+(4*n));
    int pos = 0;
    dist[pos++] = vet[0];
    for(int i = 1; i < 4*n; i++){
      if(vet[i] != vet[i-1]){
        dist[pos++] = vet[i];
      }
    }

    int x = me*ma;


    bool val = true;
    for(int i = 0; i < pos; i++){
      if(vis[vet[i]]  == 0) continue;
      if( vis[vet[i]] % 2 != 0 || x % vet[i] != 0 || vis[(x/vet[i]) ] < vis[vet[i]]){
        val = false;
        break;
      }

      vis[ (x/vet[i]) ] -= vis[vet[i]];
      vis[vet[i]] = 0;
    }
    if(val) printf("YES\n");
    else printf("NO\n");
  }
}
