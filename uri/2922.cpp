#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  while(scanf("%d %d", &a, &b)!=EOF){
    if(a == b) printf("0\n");
    else printf("%d\n", abs(a-b)-1);
  }
  return 0;
}
