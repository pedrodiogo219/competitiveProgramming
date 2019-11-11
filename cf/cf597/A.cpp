#include<bits/stdc++.h>
using namespace std;

int main(){

  int n; scanf("%d", &n);
  while(n--){
    int a, b;
    scanf("%d %d", &a, &b);
    if( __gcd(a, b) == 1) printf("Finite\n");
    else printf("Infinite\n");
  }
}
