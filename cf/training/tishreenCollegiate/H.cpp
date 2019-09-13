#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

vector<pair<int,int> > v;
int n, freq[N];

int main()
{
    int t, k;
    scanf("%d", &t);

    while(t--) {
      v.clear();
      memset(freq, 0, sizeof freq);
      scanf("%d %d", &n, &k);

      for(int i=0; i<n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({a,i});
        v.push_back({b,i});
        v.push_back({c,i});
      }

      sort(v.begin(), v.end());
      int ans=0;

      for(int i=0; i<(int)v.size() && k; i++) {
        if(freq[v[i].second] < 2) {
          k--;
          ans+=v[i].first;
          freq[v[i].second]++;
        }
      }
      printf("%d\n", ans);

    }
}
