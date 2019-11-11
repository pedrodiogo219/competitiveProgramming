#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

bool isPrime(int x){
  if(x == 0) return false;
  if(x == 1) return false;
  for(int i = 2; i*i <= x; i++){
    if(x%i == 0) return false;
  }
  return true;
}

void listPrimes(){
  for(int i = 1; i <= 1000; i++){
    if( isPrime(i) )
      primes.push_back(i);
  }
}


bool superPrimo(int x){

  int lo = 0, hi = primes.size()-1;
  int mid, p;
  while(lo <= hi){
    mid = (lo+hi)/2;
    p = primes[mid];

    if( p*p == x ) return true;
    if( p*p <  x ) lo = mid+1;
    if( p*p >  x ) hi = mid-1;
  }
  return false;
}

int main(){
  listPrimes();

  int n; scanf("%d", &n);
  int x;
  while(n--){
    scanf("%d", &x);

    if( superPrimo(x) ) puts("S");
    else puts("N");

  }

}
