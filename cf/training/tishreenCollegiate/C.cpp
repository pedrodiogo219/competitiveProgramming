#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while (t-- > 0){
    long long k, p, n;
    scanf("%lld %lld %lld", &k, &p, &n);
    printf("%lld\n", max(0LL, k-p)*n);
  }
}
