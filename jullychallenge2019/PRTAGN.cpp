#include<bits/stdc++.h>
using namespace std;

int acesos(int a){
  int sum = 0;
  for(int i = 0; (1 << i) <= a; i++){
    if( a & (1<<i) ) sum++;
  }

  return sum;
}

int main(){
  int t; cin >> t;
  while(t--){
    int q, x, impar, par; cin >> q;
    set<int> s;
    while(q--){
      cin >> x;
      impar = 0; par = 0;

      for(auto it = s.begin(); it != s.end(); ++it){
        if( (*it) == x) continue;
        s.insert( (*it)^x );
      }
      s.insert(x);

      for(auto it = s.begin(); it != s.end(); ++it){
        if( acesos( (*it) ) %2 == 0) par++;
        else impar++;
      }
      cout << par << " " << impar << endl;
    }
  }
}
