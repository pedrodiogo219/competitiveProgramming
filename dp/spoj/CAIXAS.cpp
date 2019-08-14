#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int caixa[1010][1010];
int altura[1010];

ll dp(int pos, int altura)



int main(){
  int num_caixas, num_pilhas;

  while(scanf("%d %d", &num_caixas, &num_pilhas), (num_caixas!=0 && num_pilhas!=0) ){
    for(int i = 0; i < num_pilhas; i++){
      scanf("%d", altura[i]);
      for(int j = 0; j < altura[i]; j++){
        scanf("%d", &caixa[i][j]);
      }
    }
  }
}
