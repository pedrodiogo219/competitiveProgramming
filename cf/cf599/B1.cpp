#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

vector<int> pos;
int n, m;
string s, T;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    cin >> n;
    cin >> s;
    cin >> T;

    int cont = 0;
    for(int i = 0; i < n; i++){
      if(s[i] != T[i]){
        cont++;
        pos.push_back(i);
      }
    }

    if(cont == 2){
      if(s[pos[0]] == s[pos[1]] && T[pos[0]] == T[pos[1]] )
        cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else cout << "No" << endl;

    pos.clear();
  }
}
