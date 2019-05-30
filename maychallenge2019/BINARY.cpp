#include<bits/stdc++.h>
using namespace std;

int s[1000010];
int res[1000010];
int n, x;

void processa(){
  int atraso = 0;
  int dist = 0;

  for(int i=n-1;i>=0;i--){
    res[i] = 1;

    if(s[i]==1){
      dist++;
      atraso = max(0, atraso-1);
    }else{
      printf("To na posicao: %d\n", i);
      printf("atraso: %d\n", atraso);
      printf("dist: %d\n\n", dist);

      int pos = i+x- min( max(x-dist, 0) , atraso);

      pos = min(n-1, pos);
      pos = max(pos, i);
      atraso++;
      dist = 0;
      n=pos;
      res[pos] = 0;
    }
  }
}


int main(){
  int t; scanf("%d", &t);
  while(t--){


    scanf("%d %d", &n, &x);
    for(int i=0;i<n;i++)
      scanf("%d", &s[i]);


    int N = n;
    processa();

    printf("%d", res[0]);
    for(int i=1;i<N;i++){
      printf(" %d", res[i]);
    }
    printf("\n");

  }
}
