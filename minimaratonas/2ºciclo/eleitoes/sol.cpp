#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, m; scanf("%d %d", &n, &m);

  int aux;
  set<int> u1, u2;

  for(int i = 0; i < n; i++){
    scanf("%d", &aux);
    u1.insert(aux);
  }
  for(int i = 0; i < m ; i++){
    scanf("%d", &aux);
    u2.insert(aux);
  }

  if(u1.size() > u2.size()){
    printf("Hadonaro\n");
  }
  else if(u1.size() < u2.size()){
    printf("Bolsohad\n");
  }
  else{
    printf("Empate\n");
  }

}
