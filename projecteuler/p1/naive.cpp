#include<bits/stdc++.h>
using namespace std;

int main(){

  int n = 1000;
  int i = 0;
  unsigned long long sum = 0;
  while( ++i < n){
    sum += ( (i%3 == 0 || i%5 == 0) ? i : 0 );
  }
  printf("%llu\n", sum);

}
