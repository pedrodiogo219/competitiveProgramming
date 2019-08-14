#include<bits/stdc++.h>
using namespace std;

#define NMAX 5100
#define LOG 20

int n, h[NMAX], p[NMAX][LOG];
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

  int d = h[u] - h[v];
  for(int i = 0; (1<< i) <= d; i++){
    if(d & (1<<i)) u = p[u][i];
  }

  if(u == v) return v;

  for(int k = LOG-1; k >= 0; k--){
    if(p[u][k]!=p[v][k]){
      u = p[u][k];
      v = p[v][k];
    }
  }

  return p[u][0];
}

int sobe(int u, int d){
  for(int i = 0; (1<< i)<= d ; i++){
    if(d & (1<<i)) u = p[u][i];
  }

  return u;
}

int main(){
  while(true){
    scanf("%d", &n);
    if(n == 0) break;
    int a, b;
    for(int i = 1; i < n; i++){
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    h[0] = -1;
    dfs(1, 0);

    int q, lc, ans; scanf("%d", &q);
    while(q--){
      scanf("%d %d", &a, &b);
      if(h[a] < h[b]) swap(a, b);
      lc = lca(a, b);
      int ha = h[a] - h[lc];
      int hb = h[b] - h[lc];
      int dif = abs(ha-hb);
      // printf("lca: %d\n", lc);
      // printf("ha: %d  hb: %d  dif: %d\n", ha, hb, dif);
      if(dif & 1){
        a = sobe(a, hb);
        dif = dif / 2 ;
        a = sobe(a, dif);
        printf("The fleas jump forever between %d and %d.\n", min(a, p[a][0]), max(a, p[a][0]));
      }else{
        a = sobe(a, hb);
        dif = dif / 2 ;
        a = sobe(a, dif);
        printf("The fleas meet at %d.\n", a);
      }
    }
    for(int i = 0; i <= n ; i++) adj[i].clear();
  }
}
