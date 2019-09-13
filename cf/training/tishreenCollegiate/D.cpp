#include <bits/stdc++.h>
using namespace std;

const int N = 22;
int g[N];

int solve(int pos, int mask, int qtd, const int &n){
  if(pos == n){
    return qtd + __builtin_popcount(mask);
  }
  return max(solve(pos+1, mask & g[pos], qtd+1, n), solve(pos+1, mask, qtd, n));
}

int main(){
  int t;
  scanf("%d", &t);
  while (t-- > 0){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      u--, v--;
      g[u] |= (1 << v);
    }
    printf("%d\n", solve(0, (1 << n)-1, 0, n));
    memset(g, 0, sizeof g);
  }
}
