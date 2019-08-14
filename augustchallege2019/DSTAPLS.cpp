#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

ll n, m, k;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    cin >> n >> k;
    if(k == 1){
      printf("NO\n");
      continue;
    }

    if( (n/k)%k == 0) printf("NO\n");
    else printf("YES\n");
  }
}
