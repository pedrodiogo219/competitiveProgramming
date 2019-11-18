#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef pair<int, int> ii;
typedef long long ll;

#define debug(x) cerr << #x << ": " << x << endl;

#define inf 0x3f3f3f3f;

ii v[3010];

int memo[3010][3010];
int n, t;

int dp(int pos, int t){
  if(pos == n) return 0;
  if(t <= 0) return 0;
  if(memo[pos][t] != -1) return memo[pos][t];

  int ans = max( dp(pos+1, t), v[pos].second + dp(pos+1, t - v[pos].first) );
  return memo[pos][t] = ans;
}

int main(){
  int a, b;
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &a, &b);
    v[i] = {a,b};
  }

  sort(v, v+n);

  memset(memo, -1, sizeof memo);

  printf("%d\n", dp(0, t));

}
