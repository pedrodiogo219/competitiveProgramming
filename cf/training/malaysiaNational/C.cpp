#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

int t[100000], f[100000];
int main(){
  int c; scanf("%d", &c);
  int n, S;
  int cont = 1;
  while(c--){
    scanf("%d %d", &n, &S);
    int ans = -INF;
    for(int i = 0; i < n ; i++){
      scanf("%d %d", &f[i], &t[i]);
      if(t[i] <= S) ans = max(ans, f[i]);
      else ans = max(ans, f[i] - (t[i] - S));
    }
    printf("Case #%d: %d\n", cont++, ans);
  }

}
