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

  int t; cin >> t;
  while( t--){
    int n; cin >> n;
    long long int aux, soma = 0;
    for(int i = 0; i < n; i++) {
      cin >> aux;
      soma+=aux;
    }
    cout << (soma / n) + (soma % n != 0) << endl;
  }
}
