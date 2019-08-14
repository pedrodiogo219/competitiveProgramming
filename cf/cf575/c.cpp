#include<bits/stdc++.h>
using namespace std;
#define INF 100000

int xs[100100], ys[101010], es[101010], ds[101010], cs[101010], bs[101010];

int main(){
  int t; scanf("%d", &t);
  int n;
  int x, y, esq, cima, dir, baixo;
  while(t--){
    scanf("%d", &n);

    int limSup = INF, limInf = -INF, limDir = INF, limEsq = -INF;

    for(int i = 1; i <= n; i++){
      scanf("%d %d %d %d %d %d", &x, &y, &esq, &cima, &dir, &baixo);
      xs[i] = x;
      ys[i] = y;
      es[i] = esq;
      ds[i] = dir;
      cs[i] = cima;
      bs[i] = baixo;

      if(esq == 0){
        if(x > limEsq ) limEsq = x;
      }
      if(cima == 0){
        if(y < limSup) limSup = y;
      }
      if(dir == 0){
        if(x < limDir) limDir = x;
      }
      if(baixo == 0){
        if(y > limInf) limInf = y;
      }
    }

    bool flag = true;
    for(int i = 1; i <= n; i++){
      if( xs[i] < limEsq && ds[i] == 0) flag = false;
      if( xs[i] > limDir && es[i] == 0) flag = false;
      if( ys[i] < limInf && cs[i] == 0) flag = false;
      if( ys[i] > limSup && bs[i] == 0) flag = false;
    }

    if(flag){
      printf("1 %d %d\n", limEsq, limInf);
    }else{
      printf("0\n");
    }

    // printf("%d %d %d %d\n-------------\n", limEsq, limSup, limDir, limInf);
  }

}
