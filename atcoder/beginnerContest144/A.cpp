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

  int a, b; cin >> a >> b;

  if( a <= 9 && a >= 1 && b<= 9 && b>=1){
    cout << a*b << endl;
  }
  else cout << "-1" << endl;
}
