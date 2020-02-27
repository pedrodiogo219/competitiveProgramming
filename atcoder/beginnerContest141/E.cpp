#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
string s;

int memo[5010][5010];

int dp(int i, int j){
  if(j>=n) return 0;
  if(memo[i][j]!=-1) return memo[i][j];

  if(s[i]!=s[j]) return memo[i][j] = 0;
  else return memo[i][j] = min(j-i, 1+dp(i+1, j+1));

}

int main(){
  iosbase;
  tie;
  cin >> n;
  cin >> s;
  memset(memo, -1, sizeof memo);
  int ans = -1;

  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      ans = max(ans, dp(i, j));
    }
  }

  cout << ans << endl;

}
