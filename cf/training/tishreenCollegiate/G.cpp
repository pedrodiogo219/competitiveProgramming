#include<bits/stdc++.h>
using namespace std;

struct aresta{
  int u, custo;
  aresta(){
  }
  aresta(int x, int y){
    u = x; custo = y;
  }
  bool operator <(aresta outro) const{
    return (custo >= outro.custo);
  }
};

vector<aresta> adj[100100];
vector<pair < long long, long long int > > vet;

void dfs(int v, int pai, int custo_at){
  bool menor_que_eu = false;

  for(aresta a: adj[v]){
    if(a.u != pai){
      if(a.custo >= custo_at){
        dfs(a.u, v, a.custo+1);
      }else{
        dfs(a.u, v, custo_at);
        menor_que_eu = true;
        break;
      }
    }
  }

  if(!menor_que_eu){
    vet.push_back({custo_at, v});
  }
}

long long bb(int x){
  long long int lo = 0, hi = vet.size()-1;
  long long mid, ans =-1;
  while(lo <= hi){
    mid = (lo+hi)/2;
    if(vet[mid].first <= x){
      ans = vet[mid].second;
      lo = mid+1;
    }else{
      hi = mid-1;
    }
  }
  return ans;
}

int main(){
  int n, q, t, a, b, c;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &q);
    for(int i = 0 ; i < n-1; i++){
      scanf("%d %d %d", &a, &b, &c);
      adj[a].push_back(aresta(b, c));
      adj[b].push_back(aresta(a, c));
    }
    for(int i = 1; i <= n; i++){
      sort(adj[i].begin(), adj[i].end());
    }

    dfs(1, 0, 0);

    sort(vet.begin(), vet.end());
    // for(int i = 0; i < vet.size(); i++){
    //   cout << "(" << vet[i].first << " , " << vet[i].second << ")" << endl;
    // }
    long long int ans = 0;
    for(int i = 0; i < q; i++){
      scanf("%d", &a);
      // printf("%d\n", bb(a));
      ans += bb(a);
    }
    printf("%lld\n", ans);
    vet.clear();
    for(int i = 0; i <= n; i++){
      adj[i].clear();
    }
  }
}
