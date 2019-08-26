#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int dp(int pos, int pegou1){
  if(pos == n) return 0;

  if(pegou1){
    if(s[pos] == '1') return dp(pos+1, true) + 1;
    else return dp(pos+1, true);
  }else{
    int A = -1, B = -1, sol;
    if(s[pos] == '1'){
      A = dp(pos+1, true) + 1;
      B = dp(pos+1, false);
      sol = max(A, B);
    }
    else{
      sol = dp(pos+1, false) + 1;
    }
    return sol;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> s;
  n = s.size();
  cout << dp(0, 0) << endl;
}
