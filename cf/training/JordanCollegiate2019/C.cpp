#include <bits/stdc++.h>
using namespace std;

int main(){
  int s, x;
  scanf("%d %d", &s, &x);
  int ans = 0;
  while (s > 0){
    ans++;
    s/=x;
  }
  printf("%d\n", ans);
}
