#include<bits/stdc++.h>
using namespace std;

int v[100100];
int st[4*100100];
std::vector<int> z;

void build(int pos, int L, int R){
  if(L == R) {
    st[pos] = v[L];
    return;
  }

  int next = pos << 1, mid = L + (R-L)/2 ;
  build(next, L, mid);
  build(next+1, mid+1, R);
  st[pos] = max(st[next], st[next+1]);
}

int query(int pos, int L, int R, int i, int j){
  if( i <= L && R <= j) return st[pos];

  if( L > j || R < i) return -1;

  int next = pos << 1, mid = L + (R-L)/2;

  int filho1 = query(next, L, mid, i, j);
  int filho2 = query(next+1, mid+1, R, i, j);

  // cout << "filho1: " << filho1 << "  filho2: " << filho2 << endl;

  return max(filho1, filho2);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long int n;
  int q; scanf("%lld %d", &n, &q);
  for(int i = 0; i < n ; i++){
    scanf("%d", &v[i]);
  }

  build(1, 0, n-1);

  z.push_back(-1);
  int atual = v[0];
  for(int i= 1; i < n; i++){
    z.push_back(min(v[i], atual));
    atual = max(atual, v[i]);
  }

  // for(int i = 0; i < 4*n ; i++){
  //   cout << st[i]<< " ";
  // }
  // cout << endl;

  long long int tam;
  while(q--){
    scanf("%lld", &tam);
    if(tam < n){
      cout << query(1, 0, n-1, 0, tam-1) << " " << v[tam] << endl;
    }else{
      cout << query(1, 0,  n-1, 0, n-1) << " " << z[ ( (tam-n) % (n-1)) + 1] << endl;
    }
  }

}
