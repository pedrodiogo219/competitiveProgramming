#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, a , b;
  cin >> n >> a >> b;

  n -= a;
  int ans = 0;
  ans = min(b+1, n);
  cout << ans << endl;
}
