#include<bits/stdc++.h>
using namespace std;

int v[1000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int n;
  cin >> n;
  for(int i = 0; i < n ; i++) cin >> v[i];

  bool subida = true;
  for(int i = 1; i+i < n; i++){
    if(!(v[i] > v[i-1])){
      subida = false;
    }
  }

  bool descida = true;
  for(int i = n/2 + 1; i < n; i++){
    if( !(v[i] < v[i-1]) ){
      descida = false;
    }
  }

  if(descida && subida) cout << "montanha" << endl;
  else cout << "impostora" << endl;
}
