#include<bits/stdc++.h>
using namespace std;

int main(){
  int n = 1000;
  n--;
  int n3 = n - n%3;
  int n5 = n - n%5;
  int n15 = n - n%15;

  unsigned long long sum3 = ((n3 + 3LL) * (n3/3LL))/2LL;
  unsigned long long sum5 = ((n5 + 5LL) * (n5/5))/2LL;
  unsigned long long sum15 = ((n15 + 15LL) * (n15/15LL))/2LL;

  printf("%llu\n", sum3+sum5-sum15);
}
