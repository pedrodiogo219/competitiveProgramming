#include<bits/stdc++.h>
using namespace std;

int main(){

  int n; string s = "", lixo;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> lixo;
    if(i) s+=' ';
    s+=lixo;
  }

  int q; cin >> q;
  string ans = "";
  bool active = false;
  string tecla;

  while(q--){
    cin >> tecla;
    if(tecla == "Backspace"){
      if(ans.size() > 0)
        ans.pop_back();
    }
    else if(tecla == "Space") ans+=' ';
    else if(tecla == "CapsLock"){
      active ^= true;
    }

    else{
      if(active) ans+= toupper(tecla[0]);
      else ans+=tecla;
    }
  }

  // cout << s << endl;
  // cout << ans << endl;
  if(ans == s) cout << "Correct" << endl;
  else cout << "Incorrect" << endl;
}
