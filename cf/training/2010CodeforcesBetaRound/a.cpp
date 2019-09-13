#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n, m, a;
  cin >> n >> m >> a;

  cout << ((long long)n/a + (n%a != 0)) * (m/a + (m%a!=0)) << endl;
}
