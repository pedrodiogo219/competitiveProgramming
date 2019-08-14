#include <bits/stdc++.h>
using namespace std;

bitset<10000100> vis;

int main()
{
  long long int p, n;
  scanf("%lld %lld", &p, &n);
  if(n > p){
    n%=p;
    if(n == 0) n = p;
  }

  long long int pos = 0, cont = 0;
  cont++;
  vis[0] = 1;

  for(long long int pulo = 1; pulo <= n; pulo++){
    pos = (pos + pulo) % p;
    if(vis[pos] == 0){
      cont++;
      vis[pos] = 1;
    }
  }

  printf("%lld\n", cont);
}
