#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
int main(){
  iosbase;
  tie;

  string s;
  int n;
  cin >> n;
  cin >> s;

  if( n & 1) cout << "No" << endl;
  else{
    bool errou = false;
    for(int i = 0; i < n/2; i++){
      if(s[i] != s[i + (n/2)]){
        errou = true;
        break;
      }
    }

    if(errou) cout << "No" << endl;
    else cout << "Yes" << endl;

  }
}
