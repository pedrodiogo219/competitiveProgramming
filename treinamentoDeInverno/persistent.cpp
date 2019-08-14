#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NMAX = 101010;


struct no{
  int l, r;
  ll val;
  no(){
    l = -1;
    r = -1;
    val = 0;
  }
};

no st[10101010];
int noCount, root [NMAX], rootCount;

ll sum(int idx, int L, int R, int a, int b){
  // printf("idx: %d    val: %lld\n", idx, st[idx].val);
  // printf("intervalo [%d, %d]\n", L, R);
  // printf("filhos:  %d  %d\n\n", st[idx].l, st[idx].r);
  if( L > b || R < a) return 0;
  if( a<=L && R<=b) return st[idx].val;

  int mid = (L+R)>>1;

  ll s1 = sum( st[idx].l, L, mid, a, b);
  ll s2 = sum( st[idx].r, mid+1, R, a, b);

  return s1+s2;
}


// FIZ DESSE JEITO SEM OLHAR, FUNCIONA MAS É MAIS LENTO
// int update(int idx, int L, int R, int pos, int val){
//   no Novo = st[idx];
//   if(L==R){
//     Novo.val = val;
//     st[++noCount] = Novo;
//     return noCount;
//   }
//   int mid = (L+R) >> 1;
//
//   if(pos <= mid){
//     Novo.l = update(st[idx].l, L, mid, pos, val);
//   }else{
//     Novo.r = update(st[idx].r, mid+1, R, pos, val);
//   }
//   Novo.val = st[Novo.l].val + st[Novo.r].val;
//   st[++noCount] = Novo;
//   return noCount;
// }

// JEITO MAIS RAPIDO
int update(int idx, int L, int R, int pos, int val){
  int Novo = ++noCount;
  st[Novo] = st[idx];
  if(L==R){
    st[Novo].val = val;
    return Novo;
  }
  int mid = (L+R) >> 1;

  if(pos <= mid){
    st[Novo].l = update(st[idx].l, L, mid, pos, val);
  }else{
    st[Novo].r = update(st[idx].r, mid+1, R, pos, val);
  }
  st[Novo].val = st[ st[Novo].l ].val + st[ st[Novo].r ].val;
  return Novo;
}

int main(){

  int tc; scanf("%d", &tc);
  while(tc--){
    noCount = 0;
    rootCount = 0;
    root[0] = 0;
    int n, p; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      scanf("%d", &p);
      root[0] = update(root[0], 1, n, i, p);
    }

    int q; scanf("%d", &q);
    int op, x, y, k;

    while(q--){
      scanf("%d %d %d", &op, &x, &y);
      if(op == 1){
        scanf("%d", &k);
        printf("%lld\n", sum(root[k], 1, n, x, y));
      }
      else{
        root[rootCount+1] = update(root[rootCount], 1, n, x, y);
        rootCount++;
      }
    }
  }
}
