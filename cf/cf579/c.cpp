#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(a == 0) return b;
  return gcd(b%a, a);
}

int main(){
  int n;
  long long a, g;
  scanf("%d", &n);

  scanf("%lld", &g);
  for(int i = 1; i < n; i++){
    scanf("%lld", &a);
    g = gcd(a, g);
  }

  int cont = 0;
  for(long long int i = 1; i*i <= g; i++){
    if(g%i == 0){
      cont+=2;
      if(i*i == g) cont -= 1;
    }
  }
  if(g == 1) printf("1\n");
  else
  printf("%d\n",cont);
}
