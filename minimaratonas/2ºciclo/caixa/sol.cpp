#include<bits/stdc++.h>
using namespace std;


long long int v[10000];
int main(){

  long long int n, x;
  scanf("%lld %lld", &n, &x);
  for(int i = 0; i < n; i++){
    scanf("%lld", &v[i]);
  }

  sort(v, v+n, greater<long long int>());

  // for(int i =0; i < n; i++){
  //   cout << " " <<v[i];
  // }cout << endl;

  long long int cont = 0;
  for(int i = 0; i < n ; i++){
    cont += x/v[i];
    x %= v[i];
  }

  if(x!=0) printf("-1\n");
  else printf("%lld\n", cont);
}
