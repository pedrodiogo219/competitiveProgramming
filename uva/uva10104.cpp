#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int & x, int & y){
  if(a == 0){
    x = 0;
    y = 1;
    return b;
  }

  int x1, y1;
  int g = gcd(b % a, a, x1, y1);
  y = x1;
  x = y1 - (b/a)*x1;
  return g;
}

int main(){
  int n, m;
  int x, y, g;
  while(scanf("%d %d", &n, &m)!=EOF){
    bool trocou = false;
    if(m >= n){
      swap(m, n);
      trocou = true;
    }
    g = gcd(n, m, x, y);
    if(trocou){
      swap(m, n);
      swap(x, y);
    }
    printf("%d %d %d\n", x, y, g);

  }
}
