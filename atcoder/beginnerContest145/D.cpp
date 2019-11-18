#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define mod 1000000007

long long fat(long long int x){
  long long res = 1;
  for(int i = 1; i <= x; i++){
    res = (res * i)%mod;
  }
  return res;
}

long long fast_expo(long long int b, long long int e){
  if(e == 0) return 1LL;
  if(e == 1) return b;
  long long res = 1;
  if(e & 1) res = (res*b)%mod;
  return (res*fast_expo((b*b)%mod, e/2))%mod;
}

long long mydiv(long long int a, long long int b){
  return (a * fast_expo(b, mod-2))%mod;
}
int main(){

int n, m;
  iosbase;
  tie;

  int x, y;
  cin >> x >> y;
  if(y > x) swap(y, x);
  int cont = 0;
  for(int i = 0; i <= x; i++){
    if( (x-i)%2 != 0 ) continue;
    int num2 = (x - i)/2;
    if( (y - (i*2) - num2) == 0 ){
      long long p1 = fat(i+num2);
      long long p2 = (fat(i) * fat(num2))%mod;
      cout << mydiv(p1, p2) << endl;
      return 0;
    }
  }

  cout << "0" << endl;

  return 0;
}
