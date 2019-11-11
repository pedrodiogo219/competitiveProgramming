#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long a[100100];
long long dp[100100];

int main(){
  int t; scanf("%d", &t);
  int n;
  while(t-- > 0){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      scanf("%d", &a[i]);
    }

    dp[1] = a[1] - 1LL;

    long long mult = a[1];

    for(int i = 1; i < n; i++){
      dp[i+1] = ( ((a[i+1] * dp[i])%mod) + (( (a[i+1] - 1) * mult )%mod)  )%mod;
      mult = (mult * a[i+1])%mod;
    }

    printf("%lld\n", dp[n]);
  }




}
