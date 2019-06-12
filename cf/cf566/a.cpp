#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  cin >> n;
  if(n%2 != 0) cout << "0" << endl;
  else {

    n/= 2;
    long long sol = pow(2, n);
    cout << sol << endl;
  }
}
