#include<bits/stdc++.h>
using namespace std;

#define NMAX 1000

int n, m, visitados[NMAX], distancia[NMAX];
vector<int> adj[NMAX];
queue<int> fila;

void bfs(int inicio){
  memset(visitados, 0, sizeof visitados);
  fila.push(inicio);
  visitados[inicio] = 1;
  distancia[inicio] = 0;

  while(!fila.empty()){
    int u = fila.front();
    fila.pop();

    for(int v: adj[u]){
      if(!visitados[v]){
        fila.push(v);
        visitados[v] = 1;
        distancia[v] = distancia[u]+1;
      }
    }
  }
}



int conta_componentes(){
  int contador = 0;
  for(int i = 1; i<=n; i++){
    if(!visitados[i]){
      bfs(i);
      contador++;
    }
  }

  return contador;
}

int main(){
  scanf("%d %d", &n, &m);
  int a, b;
  for(int i=0; i<m; i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}
