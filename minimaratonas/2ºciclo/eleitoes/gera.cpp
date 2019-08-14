#include<bits/stdc++.h>
using namespace std;

#define N 10
#define A 10

int main(){
  srand(time(NULL));
  int n, m;
  n = rand()%N + 1;
  m = rand()%N + 1;


  printf("%d %d\n", n, m);

  for(int i = 0; i < n;){
    int rep = rand()%3 + 1;
    int x = rand()%A + 1;
    for(int j = 0; j < rep && i < n; j++){
      if(i) printf(" ");
      printf("%d", x);
      i++;
    }
  }
  printf("\n");

  for(int i = 0; i < m; ){
    int rep = rand()%3 + 1;
    int x = rand()%A + 1;
    for(int j = 0; j < rep && i < m; j++){
      if(i) printf(" ");
      printf("%d", x);
      i++;
    }
  }
  printf("\n");


}
