#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    std::vector<int> v(n+5);
    for(int i=0; i < n; i++) cin >> v[i];

    std::vector<int> vis(200100, 0);
    int max = -1;
    for(int i = 0; i < n; i++){
      int atual = v[i];
      set<int> s;
      for(auto el: v){
        s.insert(v);
      }

      

    }
  }

  for(auto it = s.begin(); it!=s.end(); ++it){
    cout << *it << endl;
  }

}
