#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

int n;
priority_queue<ll, vector<ll>, greater<ll> > pq;

int main()
{
  int tc;
  scanf("%d", &tc);

  for(int C=1; C<=tc; C++) {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
      int x;
      scanf("%lld", &x);
      pq.push(2*x);
    }
    ll t=0, c=0;
    int ans=0;
    while(pq.size()) {
      ll d = pq.top(); pq.pop();

      if(d - t + c >= d/2) {
        ans++;
        c+=(d-t)-d/2;
        t = d;
      }
      else {
        c+=(d-t);
        t = d;
      }
    }
    printf("Case #%d: %d\n", C, ans);
  }
}
