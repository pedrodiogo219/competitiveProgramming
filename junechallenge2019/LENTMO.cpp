#include<bits/stdc++.h>
using namespace std;

long long int v[10100];
int k, x;
int n;
long long total_sum;
long long original[10100];

pair< int, int> substitui_pela_diferenca(){
  int pos = 0;
  int val;
  for(int i = 1; i <= n ; i++){
    total_sum+=v[i];
    v[i] = (v[i] ^ x) - v[i];
    original[i] = v[i];
    if(v[i] > 0) pos++;
  }

  sort(v+1, v+n+1, greater<int>());
  sort(original+1, original+n+1, greater<int>());

  for(int i = 1; i <= n; i++) v[i] += v[i-1];
  // for(int i = 1; i <= n; i++) cout << " " << v[i];
  // cout << endl;

  return {pos, n-pos};
}


// void printa_vetor(){
//   for(int i  = 1; i <= n; i++){
//     if(i) printf(" ");
//     printf("%lld", v[i] - v[i-1]);
//   }
//   printf("\n");
// }


int main(){
  int t; scanf("%d", &t);
  while(t--){
    scanf("%d", &n);

    v[0] = 0;
    original[0] = 0;
    total_sum = 0;
    for(int i = 1;i <= n ; i++) scanf("%lld", &v[i]);

    scanf("%d %d", &k, &x);

    pair<int, int> tamanhos = substitui_pela_diferenca();
    //printa_vetor();

    if(tamanhos.second >= k-1){
      long long s = tamanhos.first;
      // printf("positivos: %lld\n", s);
      if(s%2!=0) s--;
      // printf("total_sum: %lld\n", total_sum);
      long long soma = total_sum + v[s];
      // printf("soma: %lld\n", soma);
      if(tamanhos.first%2!=0){
        soma = max(soma, soma + v[tamanhos.first+k-1] - v[tamanhos.first-1]);
      }
      printf("%lld\n", soma);
    }
    else{
      long long soma = total_sum + v[n - k + 1];
      // for(int i = 1; i <= n - k + 1; i++) v[i]*=-1;
      // for(int i = n - k + 2; i <= n ; i++) v[i] = original[i] + v[i-1];
      soma = max(soma, soma + v[n] - v[n - k]);

      printf("%lld\n", soma);
    }

  }
}
