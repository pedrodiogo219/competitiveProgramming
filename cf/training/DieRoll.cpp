#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;

  a = max(a, b);
  int ans = 6 - a + 1;

  cout << ans/__gcd(ans, 6)  << "/" << 6/__gcd(ans, 6) << endl;
}
