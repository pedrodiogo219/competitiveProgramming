#include<bits/stdc++.h>
using namespace std;


bool Eh_maiuscula(char c){
  return 'A' <= c && c <= 'Z';
}
bool Eh_minuscula(char c){
  return 'a' <= c && c <= 'z';
}

int main(){
  string a, b;

  int n; cin >> n;
  cin >> a >> b;

  bool certo = true;
  for(int i = 0; i < n; i++){
    if( Eh_minuscula(a[i]) && Eh_maiuscula(b[i])) certo = false;
    if( Eh_minuscula(b[i]) && Eh_maiuscula(a[i])) certo = false;

    if(!certo) break;
  }

  if(certo){
    cout << "parecidas" << endl;
  }else{
    cout << "diferentes" << endl;
  }

}
