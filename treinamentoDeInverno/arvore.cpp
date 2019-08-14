#include<bits/stdc++.h>
using namespace std;

#define NMAX 100

int v[NMAX], n, d[NMAX], tempo = 1, in[NMAX], out[NMAX], soma[NMAX], val[NMAX], p[NMAX], h[NMAX];
vector<int> adj[NMAX];

void dfs(int u, int pai){
  in[u] = tempo++;
  p[u] = pai;
  v[in[u]] = u; // passar arvore pro vetor

  soma[u] = val[u]; //soma de subarvore
  d[u] = d[pai] + 1; //profundidade, distancia da raiz

  int maior=-1; // altura da subarvore

  for(int v: adj[u]){
    if(v == pai) continue;
    dfs(v, u);
    maior = max(maior, h[v]);
    soma[u] += soma[v];
  }

  h[u] = maior+1;
  out[u] = tempo++;
}

bool isAncestral(int u, int v){
  return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v){

  if(d[u] < d[v]) swap(u, v); // u tem que ser o mais baixo

  while(d[u] != d[v]) u = p[u];
  //u e v estao no mesmpo nivel da arvore

  while(u!=v){ //sobe os dois juntos
    u = p[u];
    v = p[v];
  }

  return u;

}

int main(){
  scanf("%d", &n);
  int a, b;
  for(int i = 1; i < n ; i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,0); //enraiza a arvore no 1
  

}
