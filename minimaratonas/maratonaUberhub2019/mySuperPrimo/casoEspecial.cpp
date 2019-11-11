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


int main(){
  listPrimes();
  cout << primes.size() << endl;
  for(int p: primes){
    cout << p*p << endl;
  }

}
