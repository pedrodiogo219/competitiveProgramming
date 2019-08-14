#include<bits/stdc++.h>
using namespace std;

string s, t, tudo;
int p[1000100];
vector<int> occ;

void kmp(){
  tudo = t+'$'+s;
  p[0] = 0;

  for(int i = 1; i < tudo.size(); i++){
    p[i] = p[i-1];
    while(tudo[p[i]] != tudo[i] && p[i]) p[i] = p[p[i]-1];
    if(tudo[p[i]] == tudo[i]) p[i]++;

    if(p[i] >= t.size() && i>=t.size()){
      occ.push_back(i);
      //p[i] = p[p[i]-1];
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  cin >> s;
  cin >> t;
  kmp();
  int M = 0;
  for(int o : occ){
    o-=t.size()+1;
    int disDir = s.size() - o - 1;
    int disEsq = o - (t.size() - 1 );
    M = max(M, max(disDir, disEsq));
    cout << "o: " << o << endl;
    cout << "disDir: " << disDir << endl;
    cout << "disEsq: " << disEsq << endl;
  }
  cout << M << endl;

}
