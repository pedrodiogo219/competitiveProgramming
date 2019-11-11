#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

int main()
{
  ll n, k, m;
  cin >> n >> k;
  m = n%(2*k);
  ll ans = 0LL;
  if(2*k > n){
    ans = 10;
  }
  else {
    ans += 5*(((n-m)/(2*k)) + ((n-m)%(2*k) != 0));
    n -= ((2*k)-m);
    ans += 5;
    ans += 5*((n/(2*k)) + ((n%(2*k)) != 0));
  }
  cout << ans << endl;
}
