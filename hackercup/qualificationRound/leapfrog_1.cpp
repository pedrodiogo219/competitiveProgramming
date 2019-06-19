#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;

  string s;
  long long int b, p;
  for(int c = 1; c <= t; c++){
    b = 0;
    p = 0;
    cin >> s;
    for(auto e : s){
      if(e == '.') p++;
      if(e == 'B') b++;
    }

    cout << "Case #" << c << ": ";
    if( p >= 1 && b >= p ) cout << "Y" << endl;
    else cout << "N" << endl;
  
  }
}
