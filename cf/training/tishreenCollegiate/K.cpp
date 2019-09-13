#include <bits/stdc++.h>
#define mod 1000000007LL
using namespace std;

typedef long long ll;
int v[55], n;
int  dp[55][55][55][55];
string s;

ll go(int l, int r, int suml, int sumr) {
  if(l == r) {
    return (suml == sumr);
  }
  if(l+1 == r) {
    return (suml+v[l] == sumr+v[r]) || (suml+v[l]+v[r] == sumr) || (suml == sumr+v[l]+v[r]);
  }

  int &ans = dp[l][r][suml][sumr];
  if(~ans) return ans;

  ans = 0;

  if(l+1 < r) {
    ans = (int)((ll)ans + (ll) go(l+1, r, suml+v[l], sumr))%mod;
  }
  if(r-1 > l){
    ans = (int)((ll)ans + (ll) go(l, r-1, suml, sumr+v[r]))%mod;
  }

  if(suml+v[l] == sumr+v[r]) {
    ans = (int)((ll) ans + (ll)  go(l+1, r-1, 0, 0))%mod;
  }
  return ans;
}

int main()
{
  int t;

  scanf("%d", &t);
  getchar();

  while(t--) {
        cin >> s;
        n = s.size();

        for(int i=0; i<n; i++) {
          v[i] = s[i] - '0';
        }

        memset(dp, -1 , sizeof dp);

        printf("%d\n", (int)((go(0,n-1, 0, 0))%mod));
  }
}
