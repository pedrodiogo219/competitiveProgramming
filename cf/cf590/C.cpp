#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define cima 1
#define esq 2
#define dir 3
#define baixo 4

string m[2];

int n;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    int n; cin >> n;
    cin >> m[0];
    cin >> m[1];

    int ult = esq;
    int x = 0, y = 0;

    while(true){
      // debug(x);
      // debug(y);
      // cerr << endl;


      if(x == 1 && y == n){
        cout << "YES" << endl;
        break;
      }

      if(x > 1 || x < 0 || y > n || y < 0) {
        cout << "NO" << endl;
        break;
      }

      if(m[x][y] <= '2' && ult == esq){
        y++;
        ult = esq;
      }
      else if(m[x][y] > '2' && ult == esq){
        x = (x+1) % 2;
        ult = baixo;
      }
      else if(m[x][y] > '2' && (ult == cima || ult == baixo) ){
        ult = esq;
        y++;
      }
      else{
        cout << "NO" << endl;
        break;
      }
    }
  }
}
