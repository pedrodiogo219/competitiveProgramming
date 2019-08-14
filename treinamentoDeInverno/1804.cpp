#include<bits/stdc++.h>
using namespace std;

const int NMAX = 100100;
int vet[NMAX], bit[NMAX];
int n;

int soma(int lim){
  int result = 0;
  int idx = lim;
  while (idx > 0){
    result += bit[idx];
    idx -= idx & (-idx);
  }
  return result;
}

void atualiza(int lim, int x){
  int idx = lim;
  while(idx <= n){
    bit[idx] += x;
    idx += idx & (-idx);
  }
}


int main(){
  scanf("%d", &n);
  memset(bit, 0, sizeof bit);
  for(int i = 1; i <=n ; i++){
    scanf("%d", &vet[i]);
    atualiza(i, vet[i]);
  }
  getchar();
  // for(int i = 1; i <= n ; i++){
  //   printf("%d ", vet[i]);
  // } puts("");
  // for(int i = 1; i <= n ; i++){
  //   printf("%d ", bit[i]);
  // } puts("");
  int q; char c;

  while(scanf("%c %d ", &c, &q)!=EOF){
    // printf("%c %d\n", c, q);
    if(c == 'a'){
      atualiza(q, -vet[q]);
    }
    else if(c == '?'){
      printf("%d\n", soma(q-1));
    }
    // for(int i = 1; i <= n ; i++){
    //   printf("%d ", bit[i]);
    // } puts("");
  }
}
