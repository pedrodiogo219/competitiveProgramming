#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();cout.tie();

  int n, m;
  cin >> n >> m;

  string s; cin >> s;
  reverse(s.begin(), s.end());

  int pos = 0;
  int caiu = 0;
  bool possivel = true;
  vector<int> pulos;
  for(int i = 1; i <= n; i++){
    if(i-pos > m){
      if(caiu == pos){
        possivel = false;
        break;
      }
      pulos.push_back(caiu - pos);
      pos = caiu;
    }
    if(s[i] == '0' && i - pos <= m){
      caiu = i;
    }
  }
  if(possivel){
    pulos.push_back(n - pos);
  }

  if(!possivel) cout << "-1" << endl;
  else{
    for(int i = (int)pulos.size() - 1; i >= 0; i--){
      cout << pulos[i];
      if(i !=0) cout << " ";
    }
    cout << endl;
  }

}
