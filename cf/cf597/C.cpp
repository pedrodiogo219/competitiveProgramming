#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

string s;
long long int dp[100100];



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  cin >> s;
  s = ' ' + s;
  dp[0]=1LL;

  int pos;
  for(int i = 1; i <= s.size(); i++){
    dp[i] = dp[i-1];
    if(s[i] == 'n' && s[i-1] == 'n') dp[i] = (dp[i] + dp[i-2])%mod;
    if(s[i] == 'u' && s[i-1] == 'u') dp[i] = (dp[i] + dp[i-2])%mod;
    if(s[i] == 'm' || s[i] == 'w') dp[i] = 0LL;
  }

  cout << dp[s.size()-1] << endl;

}
