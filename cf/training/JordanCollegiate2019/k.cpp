#include <bits/stdc++.h>
using namespace std;

 typedef unsigned long long ull;

 ull v[21], n, sum=0;

int main()
{
  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> v[i];
  }

  for(int i=0; i<(1<<n); i++) {
    ull aux=0;

    for(int j=0 ; j<n; j++) {
      if(i&(1<<j)) {
        aux|=v[j];
      }
    }
    sum+=aux;
  }

  cout << sum << endl;
}
