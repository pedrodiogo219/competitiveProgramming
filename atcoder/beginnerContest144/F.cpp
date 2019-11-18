#include <bits/stdc++.h>
using namespace std;

const int N = 606;
vector < int > g[N];
int memo[N][N], n;
double dp[N][N];

double solve(int blocked, int u){
  double resp = .0;
  if(u == n) return .0;
  double mx = -1;
  int mx_vtx;
  if(g[u].size() == 0) return 1e9;
  if(memo[blocked][u] != -1) return dp[blocked][u];
  memo[blocked][u] = 1;
  for (int v : g[u]){
    double aux = solve(blocked, v);
    resp += aux;
    if(mx < aux) {
      mx = aux, mx_vtx = v;
    }
  }
  if(u != blocked){
    return dp[blocked][u] = (resp/(double)g[u].size()) + 1;
  }
  else {
    resp -= solve(blocked, mx_vtx);
    if(g[u].size() == 1) return dp[blocked][u] = 1e9;
    return dp[blocked][u] = (resp/((double)g[u].size()-1)) + 1;
  }
}

int main(){
  int m;
  scanf("%d %d", &n, &m);
  for (int i=0; i<m; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
  }
  memset(memo, -1, sizeof memo);
  double ans = solve(0, 1);
  for (int i=1; i<=n; i++){
    ans = fmin(ans, solve(i, 1));
  }
  printf("%.8lf\n", ans);
}
