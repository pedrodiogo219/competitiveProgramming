#include<bits/stdc++.h>
using namespace std;

#define N 100000

int not_prime[101010];
vector<long long int> primes;

void crivo(){
  memset(not_prime, 0, sizeof(not_prime));
  for(int i = 2; i < N ; i++){
    if(not_prime[i]) continue;
    primes.push_back(i);
    for(int k = i+i; k < N; k+=i){
      not_prime[k] = 1;
    }
  }
}

vector<long long int> fatora(long long int x){
  if(x == 1){
    vector<long long int> v;
    return v;
  }
  vector<long long int> fatores;
  int i = 0;
  while(primes[i] * primes[i] <= x){
    if(x % primes[i] == 0){
      fatores.push_back(primes[i]);
      while(x % primes[i] == 0) x/= primes[i];

      vector<long long int> outros = fatora(x);
      for(auto it = outros.begin(); it != outros.end(); ++it){
        fatores.push_back((*it));
      }
      return fatores;
    }
    i++;
  }

  fatores.push_back(x);
  return fatores;

}

int main(){
  crivo();
  int t; scanf("%d", &t);
  long long dif, bigPrime = primes[primes.size()-1];
  while(t--){
    printf("1 %lld\n", bigPrime);
    fflush(stdout);

    scanf("%lld", &dif);

    if(dif == 0){
      printf("2 %lld\n", bigPrime);
      fflush(stdout);

      char s[5];
      scanf("%s", s);
      if(strcmp(s, "No") == 0) exit(1);
    }
    else{
      long long int aq = bigPrime*bigPrime - dif;
      vector<long long int> possiveis = fatora(aq);

      // for(auto ele: possiveis){
      //   printf("%lld ", ele);
      // }printf("\n");

      long long ans = -1;

      int lo = 0, hi = possiveis.size()-1, mid;
      while(lo <= hi){
        mid = lo + (hi-lo)/2;

        printf("1 %lld\n", possiveis[mid]);
        fflush(stdout);
        scanf("%lld", &dif);

        if(dif == 0){
          ans = possiveis[mid];
          break;
        }

        if(dif == possiveis[mid]*possiveis[mid]){
          lo = mid+1;
        }
        else{
          hi = mid-1;
        }
      }

      printf("2 %lld\n", ans);
      fflush(stdout);

      char s[5];
      scanf("%s", s);
      if(strcmp(s, "No") == 0) exit(1);
    }


  }
}
