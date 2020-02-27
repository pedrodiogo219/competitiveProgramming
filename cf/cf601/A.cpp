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
    int a, b;
    cin >> a >> b;
    int dif = abs(a-b);

    int cont = 0;

    cont+= dif/5;
    dif%=5;
    cont+=dif/2;
    dif%=2;
    cont+=dif;
    cout << cont << endl;
  }
}
