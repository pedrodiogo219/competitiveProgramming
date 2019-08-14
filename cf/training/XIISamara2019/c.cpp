#include <bits/stdc++.h>
#define INF 10000007
using namespace std;

typedef long long ll;

const int N = 10000007;
ll v[N];

void process(ll p, ll n) {
  for(int i=0; i<p; i++) v[i] = INF;
  v[0] = 0;

  int u = 0;

  for(int i=1; i<=p; i++) {
    int w = (u+i)%p;
    v[w] = min(v[u]+1, v[w]);
    u = w;
  }
}


int main()
{
  long long int p, n;
  scanf("%lld %lld", &p, &n);

  process(p, n);

  ll ans = 0;

  for(int i=0; i<p; i++)
    if(v[i] <= n) ans++;

  cout << ans << endl;
}
