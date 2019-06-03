#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v;
  int n; scanf("%d", &n);
  long long total = 0;
  for(int i=0;i<n+n;i++){
  int aux; scanf("%d", &aux);
    v.push_back(aux);
    total+=aux;
  }

  sort(v.begin(), v.end());
  long long partial=0;
  for(int i=0;i<n;i++){
    partial+=v[i];
  }

  if( partial == total-partial){
  printf("-1\n");
  }else{
    for(int i=0;i<n+n; i++){
    if(i) printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
  }
}
