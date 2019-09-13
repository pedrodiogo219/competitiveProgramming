#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

vector < int > path;
const int N = 55;
const int T = 1005;

int dp[N][T], n, vet[N];

int solve(int pos, int remain){
  if(pos == n) return remain;
  int &ans = dp[pos][remain];
  if(ans != -1) return ans;
  ans = oo;
  if(vet[pos] <= remain) ans = min(ans, solve(pos+1, remain-vet[pos]));
  ans = min(ans, solve(pos+1, remain));
  return ans;
}

void recover(int pos, int remain){
  if(pos == n) return ;
  if(vet[pos] <= remain && solve(pos+1, remain-vet[pos]) == dp[pos][remain]){
    path.push_back(vet[pos]);
    recover(pos+1, remain- vet[pos]);
    return ;
  }
  recover(pos+1, remain);
  return ;
}

int main(){
  int t;
  while (scanf("%d", &t), t){
    scanf("%d", &n);
    int sum = 0;
    for (int i=0; i<n; i++){
      scanf("%d", &vet[i]);
      sum += vet[i];
    }
    memset(dp, -1, sizeof dp);
    sum = solve(0, t);
    recover(0, t);
    for (int x : path) printf("%d ", x);
    printf("%d\n", t-sum);
    path.clear();
  }
}
