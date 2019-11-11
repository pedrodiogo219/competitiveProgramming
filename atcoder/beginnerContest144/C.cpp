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

  long long int x; cin >> x;
  long long int ans = 99999999999999999;
  for(long long int i = 1; i * i <= x; i++){
    if( x % i == 0){
      ans = min(ans, ( i - 1 + (x/i) - 1));
    }
  }

  cout << ans << endl;
}
