#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;
  string s;
  while(t--){
    cin >> s;

    bool ans = (s[0] == '1') ;
    for(int i = 1; i <s.size(); i++){
      if(s[i] == '1') ans = !ans;
    }
    if(ans) cout << "WIN" << endl;
    else cout << "LOSE" << endl;

  }
}
