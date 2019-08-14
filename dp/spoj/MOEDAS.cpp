#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int n;
int v[50100];
int memo[50100];

int dp(int money){
  if(money == 0) return 0;
  if(money < 0) return INF;

  if(memo[money]!= -1) return memo[money];

  int menor = INF;
  for(int i =0; i < n; i++){
    menor = min(menor, 1 + dp(money - v[i]) );
  }
  return memo[money] = menor;
}

int main(){
  int money;
  while(scanf("%d", &money), money!=0){
    memset(memo, -1, sizeof(memo));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &v[i]);
    }

    int result = dp(money);
    if (result <= 50000) printf("%d\n", result);
    else printf("Impossivel\n");

  }
}
