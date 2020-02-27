#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define T int t; cin >> t; while( t--)
#define sT int t; scanf("%d", &t); while( t--)

int n, m;
int main(){

  sT{
    set<int> ans;
    ll n; scanf("%lld", &n);

    ll i = 0LL;

    if(n == 1LL){
      printf("2\n0 1\n");
      continue;
    }

    for(ll i = 1; i * i <= n; i++){

      ll x = n/i;
      ans.insert( n / x);
      ans.insert(n/i);
      // debug(n/i);
    }

    printf("%d\n",( (int)ans.size()) + 1);

    printf("0");

    for(auto it: ans){
      printf(" %d", it);
    }puts("");



  }

}
