#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n);
  while(n--){

    int a, b;
    scanf("%d %d", &a, &b);

    if(a&1) printf("Kilani\n");
    else{
      if(b > a-2) printf("Ayoub\n");
      else printf("Kilani\n");
    }
  }
}
