#include<bits/stdc++.h>
using namespace std;

typedef pair<string, int> si;

string substring(string &s, int pos){
  string a = "";

  for(int i = 0; i < pos; i++) a+=s[i];
  for(int i = pos+1; i < s.size(); i++) a+=s[i];

  return a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int n, k;
  cin >> n >> k;
  string s; cin >> s;

  queue<si> fila;
  set<string> ss;

  fila.push( make_pair(s, 0) );
  long long soma = 0;
  while( !fila.empty() ){
    string sAtual = fila.front().first;
    int nivel = fila.front().second;
    fila.pop();

    if( ss.find(sAtual) == ss.end() ){
      // cout << "achei uma nova: " << sAtual << endl;
      soma+=nivel;
      ss.insert(sAtual);
      if(ss.size() == k) break;
      for(int i=0; i < sAtual.size(); i++){
        fila.push( make_pair(substring(sAtual, i), nivel+1));
      }
    }
  }

  if(ss.size() == k) cout << soma << endl;
  else cout << "-1" << endl;

}
