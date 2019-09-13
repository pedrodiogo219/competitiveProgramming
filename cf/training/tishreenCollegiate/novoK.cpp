#include<bits/stdc++.h>
using namespace std;
string s;

long long memo[55][55];

long long int dp(int l, int r){
  if(l > r) return 1LL;
  if(l == r) return 1LL;

  if(memo[l][r] != -1LL) return memo[l][r];

  long long ans = 0;

  long long sumL = 0;
  for(int i = l; i < r; i++){
    sumL+=(s[i] == '1');
    long long sumR = 0;
    for(int j = r; j > i; j--){
      sumR+=(s[j] == '1');
      if(sumL == sumR)
        ans+=dp(i+1, j-1);
    }
  }
  ans++;
  return memo[l][r] = ans;
}

int main(){
  int t; cin >> t;
  while(t-->0){
    cin >> s;
    memset(memo, -1, sizeof memo);
    cout << dp(0, s.size()-1) << endl;
  }

}
