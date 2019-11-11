#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int vet[1010];

int n, m;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> vet[i];
    }

    sort(vet+1, vet+n+1, greater<int>());

    int ans = 0;
    for(int i = 1; i <= n; i++){
      if(vet[i] >= i) ans = i;
    }
    cout << ans << endl;
  }
}
