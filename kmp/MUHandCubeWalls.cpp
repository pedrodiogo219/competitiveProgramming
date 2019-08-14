#include<bits/stdc++.h>
using namespace std;

#define INF 100000000000000

int n, w, idx;
long long int txt[200100], pattern[200100], tudo[400100];
int p[400100];
int kmp(){
  int cont = 0;
  p[0] = 0;
  for(int i = 1; i < idx; i++){
    p[i] = p[i-1];
    while(tudo[i] != tudo[p[i]] && p[i] != 0) p[i] = p[p[i]-1];
    if(tudo[i] == tudo[p[i]]) p[i]++;

    if(i >= w-1 && p[i] >= w-1) cont++;
  }

  return cont;
}

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie();
  // cout.tie();

  scanf("%d %d", &n, &w);
  long long x, novoX;

  scanf("%lld", &x);
  for(int i = 0 ; i < n-1; i++){
    scanf("%lld", &txt[i]);
    novoX = txt[i];
    txt[i] -= x;
    x = novoX;
  }

  scanf("%lld", &x);
  for(int i = 0; i < w-1; i++){
    scanf("%lld", &pattern[i]);
    novoX = pattern[i];
    pattern[i] -= x;
    x = novoX;
  }

  idx = 0;
  for(int i = 0; i < w-1; i++) tudo[idx++] = pattern[i];
  tudo[idx++] = INF;
  for(int i = 0; i < n-1; i++) tudo[idx++] = txt[i];

  if(w == 1) printf("%d\n", n);
  else printf("%d\n", kmp());
  // for(int i = 0; i < idx; i++){
  //   cout << tudo[i] << " ";
  // }cout << endl;
  // for(int i = 0; i < idx; i++){
  //   cout << p[i] << " ";
  // }cout << endl;

}
