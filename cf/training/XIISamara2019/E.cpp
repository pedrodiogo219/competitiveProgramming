#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
pair < pair < int, int >, int > vet[N];
int n, m;

struct no{
  int idx, val;
}dp[N];


int bb(int r){
  int lo = 0, hi = n-1, ans = -1;
  while (lo <= hi){
    int mid = (lo + hi) >> 1;
    if(vet[mid].first.first <= r+1){
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  return ans;
}

int main(){
  scanf("%d %d", &n, &m);
  int r  = -1, aidi=-1;
  for (int i=0; i<n; i++){
      scanf("%d %d", &vet[i].first.first, &vet[i].first.second);
      if(vet[i].first.first == 1){
        if(vet[i].first.second > r){
          r = vet[i].first.second;
        }
      }
      vet[i].second = i+1;
  }
  sort(vet, vet+n);
  dp[0].val = vet[0].first.second;
  dp[0].idx = 0;
  for (int i=1; i<n; i++){
    if(vet[i].first.second > dp[i-1].val) {
      dp[i].val = vet[i].first.second;
      dp[i].idx = i;
    }
    else dp[i] = dp[i-1];
  }
  if(r == -1){
    puts("NO");
    return 0;
  }
  for (aidi = 0; aidi < n; aidi++) {
    if(vet[aidi].first.second == r) break;
  }
  vector < int > ans;
  ans.push_back(vet[aidi].second);
  while (r < m){
    int id = bb(r);
    if(id == -1) break;
    no resp = dp[id];
    if(resp.val == r) break;
    ans.push_back(vet[resp.idx].second);
    r = resp.val;
  }
  if(r != m) puts("NO");
  else {
    puts("YES");
    printf("%d\n", (int)ans.size());
    for (int i=0; i<ans.size(); i++){
      if(i) printf(" ");
      printf("%d", ans[i]);
    }
    puts("");
  }
}
