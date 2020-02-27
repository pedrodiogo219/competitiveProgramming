#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int vis[100100];

int n, m, k, q;
int main(){
  iosbase;
  tie;

  cin >> n >> k >> q;
  for(int i = 0; i < q; i++){
    cin >> m;
    vis[m]++;
  }

  for( int i = 1; i <= n; i++){
    if( k - q + vis[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

}
