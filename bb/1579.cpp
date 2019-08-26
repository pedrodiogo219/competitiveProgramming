#include<bits/stdc++.h>
using namespace std;

int painel[1000];

int main(){
  int t; cin >> t;
  while(t--){
    int n, num_cam, preco; cin >> n >> num_cam >> preco;
    int soma = 0, maior = 0;
    for(int i = 0; i < n; i++){
      cin >> painel[i];
      soma+=painel[i];
      maior = max(maior, painel[i]);
    }

    int resposta = -1;
    int esq = maior, dir = soma, meio;
    while(esq<=dir){
      meio = (esq+dir)/2;

      int caminhoes_usados = 1, pesoAtual = 0;
      for(int i = 0; i < n; i++){
        if(pesoAtual + painel[i] <= meio){
          pesoAtual+=painel[i];
        }else{
          caminhoes_usados++;
          pesoAtual = painel[i];
        }
      }
      if(caminhoes_usados > num_cam){
        esq = meio+1;
      }else if(caminhoes_usados <= num_cam){
        resposta = meio;
        dir = meio-1;
      }
    }

    cout << resposta << " $" << resposta*num_cam*preco << endl;
  }
}
