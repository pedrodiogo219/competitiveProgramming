#include<bits/stdc++.h>
using namespace std;

class CharmingTicketsEasy{
public:
  long long int dp[52][5000];
  int k;
  string s;
  const int M = 999983;

  void prepros(){
    for(int i = 0; i <= k; i++){
      for(int j = 0; j < 5000; j++){
        dp[i][j] = 0;
      }
    }

    for(char c : s){
      dp[1][c-'0'] = 1;
    }

    for(int step = 1; step <= k; step++){
      for(int soma = 0; soma < 5000; soma++){
        for(char c: s){
          int d = c - '0';
          if(soma-d >= 0){
            dp[step][soma] += dp[step-1][soma-d];
            dp[step][soma] %= M;
          }
        }
      }
    }

    for(int i = 0; i <= k; i++){
      for(int j = 0; j <= 30; j++){
        cout << dp[i][j] << " ";
      } cout << endl;
    }
  }

  int count(int K, string good){
    k = K;
    s = good;
    prepros();

    long long ans = 0LL;

    for(int i = 0; i < 5000; i++){
      ans += (dp[k][i]*dp[k][i])%M;
      ans %= M;
    }
    ans = (ans+ans)%M;

    long long duplicates = 0;
    for(int i = 0; i < 5000; i++){
      duplicates+= dp[k][i];
      duplicates %= M;
    }

    ans = (ans - duplicates + M) % M;
    return ans;
  }

};

int main(){
  CharmingTicketsEasy c;
  int k; string s;
  cin >> k >> s;
  cout << c.count(k, s) << endl;
}
