#include<bits/stdc++.h>
using namespace std;
int main(){

  int t; cin >> t;

  string s;
  int p, b;
  for(int c = 1; c <= t ; c++){
    cin >> s;
    p = 0; b = 0;

    for(int i = 0; i<s.size(); i++){
      if(s[i] == '.') p++;
      if(s[i] == 'B') b++;
    }

    cout << "Case #" << c << ": ";

    if(p < 1) cout << "N" << endl;
    else{
      if(b >= p || b >= 2 ) cout << "Y" << endl;
      else cout << "N" << endl;
    }
  }
}
