#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int last[N], vet[N], dp[N];

int main(){
  int n;
  scanf("%d", &n);
  memset(last, -1, sizeof last);
  for (int i=0; i<n; i++){
    scanf("%d", &vet[i]);
  }
  dp[n] = 0;
  for (int i=n-1; i>=0; i--){
      dp[i] = dp[i+1]+1;
      if(vet[i] < 0 && last[-vet[i]] != -1) dp[i] = min(dp[i], last[-vet[i]] - i);
      if(vet[i] > 0) last[vet[i]] = i;
  }
  for (int i=0; i<n; i++){
    if(i) printf(" ");
    printf("%d", dp[i]);
  }
  printf("\n");
}
