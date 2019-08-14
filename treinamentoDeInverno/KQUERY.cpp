#include<bits/stdc++.h>
using namespace std;

const int NMAX = 30100;
const int QMAX = 200100;
int vet[NMAX], bit[NMAX], result[QMAX];
int n, q;
unordered_map<int, int> compress;
set<int> tudo;

void comprime(){
  int idx = 1;
  for(auto it = tudo.begin(); it!=tudo.end(); ++it){
    compress[(*it)] = idx++;
  }
}

struct query{
  int pos, k, idx, sinal;
  query(){
    pos = 0;
    k = 0;
    idx = -1;
    sinal = 0;
  }
  query(int p, int ka, int i, int s){
    pos = p;
    k = ka;
    idx = i;
    sinal = s;
  }
};

vector<query> Q[NMAX];

int ValoresNaBit = 0;

void insere(int k){
  ValoresNaBit++;
  while(k < n){
    bit[k] += 1;
    k += (k & (-k));
  }
}

int consulta(int k){
  int result = 0;
  while(k > 0){
    result+=bit[k];
    k -= (k & (-k));
  }
  // printf("consulta k: %d\n", ValoresNaBit - result);
  return (ValoresNaBit - result);
}

int main(){
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &vet[i]);
    tudo.insert(vet[i]);
  }

  scanf("%d", &q);
  int l, r, k;
  for(int i=0; i < q; i++){
    scanf("%d %d %d", &l, &r, &k);
    Q[l-1].push_back( query(l-1, k, i, -1) );
    Q[r].push_back( query(r, k, i, 1) );
    tudo.insert(k);
  }

  comprime();

  for(int i = 0; i <= n; i++){
    if(i>0){
      // printf("compress %d\n", compress[vet[i]]);
      insere(compress[vet[i]]);
    }
    query my_q;
    for(int j = 0; j < Q[i].size(); j++){
      my_q = Q[i][j];
      result[my_q.idx] += consulta(compress[my_q.k]) * my_q.sinal;
    }
  }

  for(int i = 0; i < q; i++){
    printf("%d\n", result[i]);
  }

}
