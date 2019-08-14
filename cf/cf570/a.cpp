#include<bits/stdc++.h>
using namespace std;

int somadigitos(int n){
  int soma = 0;
  while( n > 0){
    soma+= n%10;
    n/=10;
  }

  return soma;
}

int main(){

   int n; cin >> n;

   while( !(somadigitos(n)%4==0) ){
     n++;
   }
   cout << n << endl;



}
