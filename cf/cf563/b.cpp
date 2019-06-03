#include<bits/stdc++.h>
using namespace std;

int main(){
  std::vector<int> v;
  int n; scanf("%d", &n);
  int a, par = 0, impar = 0;
  for(int i=0;i<n;i++){
    scanf("%d", &a);
    if(a %2 == 0) par++;
    else impar++;
    v.push_back(a);
  }

  if(par > 0 && impar > 0){
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
      if(i) printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");

  }else{
    for(int i=0;i<n;i++){
      if(i) printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
  }
}
