#include<bits/stdc++.h>
using namespace std;

char v1[5], v2[5];

int main(){
  string s;
  for(int i = 0; i < 5; i++){
    cin >> s;
    if(s[1] == '<'){
      v1[i] = s[2];
      v2[i] = s[0];
    }else{
      v1[i] = s[0];
      v2[i] = s[2];
    }
  }

  bool ans = false;
  int P[] = {1, 2, 3, 4, 5};
  do{
    bool val = true;
    for(int i = 0; i < 5; i++){
      if(!( P[v1[i] - 'A'] > P[v2[i] - 'A'])){
        val = false;
      }
    }

    if(val){
      for(int num = 1; num < 6; num++){
        for(int i = 0; i < 5; i++){
          if(P[i] == num){
            printf("%c", 'A'+i);
          }
        }
      }printf("\n");
      ans = true;
      break;

    }
  }while(next_permutation(P, P+5));

  if(!ans) printf("impossible\n");

}
