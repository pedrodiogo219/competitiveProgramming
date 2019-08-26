#include<bits/stdc++.h>
using namespace std;

int main(){

  int vet[100000], n;

  cin >> n;
  for(int i =0 ; i <  n; i++) cin >> vet[i];

  int perguntas = 100000;
  while(perguntas--){
    int k;
    cin >> k;

    bool resposta = false;

    int esq = 0, dir = n-1, meio;
    while(esq <= dir){
      meio = (esq+dir)/2;

      if(vet[meio] == k){
        respota = true;
        break;
      }
      else if(vet[meio] > k){
        dir = meio-1;
      }
      else{
        esq = meio+1;
      }
    }

    if(resposta == true) cout << "achou" << endl;
    else cout << "nao achou" << endl;

  }

}
