#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t ; cin >> t;

  // string s;
  // int n=0;
  while(t--){
    // n++;
    //
    // stringstream ss;
    // ss << n;
    // s = ss.str();
    string s; cin >> s;

    int sum = 0;
    for(auto c : s){
      sum= (sum + (c -'0'))%10;
    }
    cout << s << (10-sum)%10 << endl;
  }
}
