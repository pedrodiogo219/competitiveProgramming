#include<bits/stdc++.h>
using namespace std;


long long int M[1010][1010];
int main(){
  int n, m;
  scanf("%d %d",&n, &m);
  long long linha, aux;

  for(int i = 0; i <= n+2; i++) M[i][0] = 0;
  for(int j = 0; j <= m+2; j++) M[0][j] = 0;

  for(int i = 1; i <= n; i++){
    linha = 0;
    for(int j = 1; j<= m; j++){
      scanf("%lld", &M[i][j]);
      aux = M[i][j];
      M[i][j]+= linha + M[i-1][j];
      linha += aux;
    }
  }
  int q, a, b, x, y; scanf("%d", &q);
  long long ans;
  while(q--){
    scanf("%d %d %d %d", &a, &b, &x, &y);
    ans = M[x][y] - M[a-1][y] - M[x][b-1] + M[a-1][b-1];
    printf("%lld\n", ans);
  }
}
