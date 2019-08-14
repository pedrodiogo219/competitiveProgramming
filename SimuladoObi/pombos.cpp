#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

long long a[100100], b[100100];
int n, melhorI, melhorJ;
long long bruta(){

  long long m = INF;
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      long long dis = 0;
      for(int k = 0; k<n; k++){
        dis+= abs(a[k] - i)+abs(b[k] - j);
      }
      if(dis <= m){
        m = dis;
        melhorI = i;
        melhorJ = j;
      }
    }
  }
  return m;
}

int main(){

  scanf("%d", &n);
  long long somaA = 0, somaB = 0;
  for(int i = 0; i < n; i++){
    scanf("%lld %lld", &a[i], &b[i]);
    somaA+=a[i];
    somaB+=b[i];
  }
  somaA/=n;
  somaB/=n;
  long long dist = 0;
  for(int i = 0; i < n; i++){
    dist+= abs(a[i] - somaA) + abs(b[i] - somaB);
  }

  long long br = bruta();
  if(br != dist) printf("EEEEEEEEEEOOOOOOOOOOOOOEEEEEEEEEO\n");
  printf("%lld\n", dist);
  printf("%lld\n", br);
  printf("%d %d, %lld %lld\n", melhorI, melhorJ, somaA, somaB);
}
