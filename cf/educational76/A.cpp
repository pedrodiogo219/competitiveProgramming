#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; scanf("%d", &t);

  while(t--){
    int x, a, b, n;
    scanf("%d %d %d %d", &n, &x, &a, &b);

    int dif = abs(a - b);
    dif = min(dif + x, n-1);
    printf("%d\n", dif);
  }
}
