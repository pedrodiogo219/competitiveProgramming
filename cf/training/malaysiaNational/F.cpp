#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
const int N = 2005;
ll dp[N][1 << 10];
int fight[N][N];

ll solve(int pos, int mask, const int &e, const int &n){
  if(pos == n) return 1LL;
  if(mask & (1 << 9)) mask ^= (1 << 9);
  ll &ans = dp[pos][mask];
  if(ans != -1) return ans;
  ans = 0;
  int p=pos;
  for (int i=4; i<9; i++, p--){
    if(p < 0 || abs(p-pos) > e) break;
    if(!(mask & (1 << i)) && !fight[pos][p]){
      if(i == 8) mask ^= (1 << i);
      ans = (ans%mod + solve(pos+1, (mask ^ (1 << i)) << 1, e, n)%mod)%mod;
    }
    else {
      if(i == 8) mask ^= (1 << i);
    }
  }
  p = pos+1;
  for (int i=3; i>=0; i--, p++){
    if(p >= n || abs(p-pos) > e) break;
    if(!(mask & (1 << i)) && !fight[pos][p]){
      ans = (ans%mod + solve(pos+1, (mask ^ (1 << i)) << 1, e, n)%mod)%mod;
    }
  }
  return ans;
}

int main(){
  int n, e, k;
  scanf("%d %d %d", &n, &e, &k);
  memset(dp, -1, sizeof dp);
  for (int i=0; i<k; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    fight[u][v] = 1;
  }
  printf("%lld\n", solve(0, 0, e, n));
}
