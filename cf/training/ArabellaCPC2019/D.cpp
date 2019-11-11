#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int vet[N];

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++){
    scanf("%d", &vet[i]);
  }
  int gcd = 0;
  for (int i=0; i<k; i++){
    int x;
    scanf("%d", &x);
    gcd = __gcd(gcd, x);
  }
  bool flag = true;
  for (int i=0; i+1<n; i++){
    if(abs(vet[i] - vet[i+1])%gcd != 0) flag = false;
  }
  puts((flag) ? "Yes" : "No");
}
