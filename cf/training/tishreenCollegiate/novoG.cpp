#include<bits/stdc++.h>
using namespace std;

struct aresta{
  int u, custo;
  aresta(){}
  aresta(int a, int b){
    u = a;
    custo = b;
  }
  bool const operator < (aresta outro){
    return custo > outro.custo;
  }
};

vector< aresta > adj[100010];
vector< pair< int, int> > v;

void dfs(int ve, int pai, int custo_atual){
  bool menor_que_eu = false;

  for(aresta a : adj[ve]){
    if(a.u == pai) continue;
    if(a.custo < custo_atual){
      menor_que_eu = true;
      dfs(a.u, ve, custo_atual);

      break;
    }
    dfs(a.u, ve, a.custo+1);
  }

  if(!menor_que_eu){
    v.push_back({custo_atual, ve});
  }
}

long long bb(int x){
  long long ans = -1, lo = 0, hi = v.size()-1, mid;
  while(lo <= hi){
    mid = (lo+hi)/2;
    if(v[mid].first <= x){
      ans = v[mid].second;
      lo = mid+1;
    }else{
      hi = mid-1;
    }
  }
  return ans;
}

int main(){
  int t; scanf("%d", &t);
  while(t--){
    int n, q; scanf("%d %d", &n, &q);
    int a, b, c;
    for(int i = 0; i < n-1; i++){
      scanf("%d %d %d", &a, &b, &c);
      adj[a].push_back(aresta(b, c));
      adj[b].push_back(aresta(a, c));
    }

    for(int i = 1; i <= n; i++){
      sort(adj[i].begin(), adj[i].end());
    }

    dfs(1, 0, 0);
    sort(v.begin(), v.end());
    // for(pair<int, int> k: v) cout << k.first << " " << k.second << endl;
    int x;
    long long ans = 0;
    while(q-- > 0){
      scanf("%d", &x);
      ans += bb(x);
    }
    printf("%lld\n", ans);
    v.clear();
    for(int i = 1; i<=n; i++) adj[i].clear();
  }
}
