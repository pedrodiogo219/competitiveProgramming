#include<bits/stdc++.h>
using namespace std;

int main(){
  int t; scanf("%d", &t);
  long long int a, b;
  while(t--){
    scanf("%lld %lld", &a, &b);

    if(a >= b){
      printf("YES\n");
      continue;
    }
    if(a & 1){
      a--;
    }
    if(a == 2 && b == 3){
      printf("YES\n");
      continue;
    }

    if(a>=4){
      printf("YES\n");
      continue;
    }

    printf("NO\n");


  }
}
