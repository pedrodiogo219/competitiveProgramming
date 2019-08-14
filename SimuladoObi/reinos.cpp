#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > adj;
unordered_map<int, bool> vis;
int entrada[100100];
int entrada2[100100];
int tudo[200200];

void dfs(int v, int pai){
  vis[v] = true;
  for(int u: adj[v]){
    if(u == pai) continue;
    if(!vis[u]) dfs(u, v);
  }
}

int main(){
  int n, m; scanf("%d %d", &n, &m);

  int a, b;
  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    entrada[i] = a;
    entrada2[i] = b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int cont = 0;
  for(int i = 0; i < m; i++){
    if(vis[entrada[i]]) continue;
    cont++;
    dfs(entrada[i], entrada[i]);
  }
  for(int i = 0; i < m; i++){
    if(vis[entrada2[i]]) continue;
    cont++;
    dfs(entrada2[i], entrada2[i]);
  }
  int pos = 0;
  for(int i = 0; i < m; i++){
    tudo[pos++] = entrada[i];
    tudo[pos++] = entrada2[i];
  }

  sort(tudo, tudo+pos);
  int distintos = 1;
  for(int i = 1; i < pos; i++){
    if(tudo[i] != tudo[i-1]) distintos++;
  }
  int outrosV = n-distintos;

  printf("%d\n", cont+outrosV-1);
}
