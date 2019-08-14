#include<bits/stdc++.h>
using namespace std;

bitset<1000000> visitados;
int distancia[1000000];

int bfs(int inicio, int destino){
  queue<int> fila;
  fila.push( inicio );
  visitados[inicio] = 1;
  distancia[inicio] = 0;

  while(!fila.empty()){
    int u = fila.front();
    fila.pop();

    if(u == destino) return distancia[u];

    if(!visitados[u+1]){
      fila.push(u+1);
      visitados[u+1] = 1;
      distancia[u+1] = distancia[u] + 1;
    }

    char s[10];
    sprintf(s, "%d", u);
    reverse(s, s+strlen(s));
    int next = atoi(s);

    // cout << "u: " << u << endl;
    // cout << "prox:" << prox << endl;
    // cout << "next:" << next << endl;
    if(!visitados[next]){
      fila.push(next);
      visitados[next] = 1;
      distancia[next] = distancia[u] + 1;
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;
  int a, b;
  while(t--){
    visitados.reset();
    memset(distancia, 0, sizeof distancia);
    cin >> a >> b;
    cout << bfs(a, b) << endl;
  }
}
