#include<bits/stdc++.h>
using namespace std;

const int NMAX = 1100;
#define LOG 12

int n, q, h[NMAX], p[NMAX][LOG];
vector<int> adj[NMAX];

void dfs(int u, int pai){
  h[u] = h[pai]+1;

  p[u][0] = pai;
  for(int k = 1; k < LOG; k++){
    p[u][k] = p[p[u][k-1]][k-1];
  }

  for(int v: adj[u]){
    if(v == pai) continue;
    dfs(v, u);
  }
}

int lca(int u, int v){
  if(h[u] < h[v]) swap(u, v);

  int d = h[u]-h[v];
  for(int i = 0; (1 << i) <= d ; i++){
    if( d & (1 << i)) u = p[u][i];
  }

  if(u == v) return v;

  for(int k = LOG-1; k >= 0; k--){
    if( p[u][k] != p[v][k] ){
      u = p[u][k];
      v = p[v][k];
    }
  }
  return p[u][0];
}

int main(){
  int tc; scanf("%d", &tc);
  for(int t = 1; t <= tc; t++){
    scanf("%d", &n);
    int filhos, a, b;
    for(int i = 1; i <= n ; i++){
      scanf("%d", &filhos);
      while(filhos--){
        scanf("%d", &a);
        adj[i].push_back(a);
        adj[a].push_back(i);
      }
    }
    dfs(1, 0);
    // printf("acabou a dfs\n");
    scanf("%d", &q);
    printf("Case %d:\n", t);
    while(q--){
      scanf("%d %d", &a, &b);
      printf("%d\n", lca(a, b));
    }

    for(int i = 0 ; i <=n; i++ ){
      adj[i].clear();
    }

  }
}
