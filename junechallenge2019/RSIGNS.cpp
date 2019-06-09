#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int fast_expo(long long int base, long long int exp){
  if(exp == 0) return 1;
  if(exp == 1) return base;

  long long int sol = fast_expo(  (base*base)%MOD , exp/2) % MOD;
  if(exp%2 == 1) sol = (sol * base)%MOD;

  return sol;

}

int main(){

  long long int n, t; cin >> t;
  while(t--){
    cin >> n;

    cout << (10LL*fast_expo(2LL, n-1))%MOD << endl;
  }
}


/*
000 999
009 990
090 909
099 900


11 88
18 81

22 77
27 72

04
05
09
10
11
12
13
14



*/
