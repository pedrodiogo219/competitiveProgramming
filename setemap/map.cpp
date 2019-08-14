/// PROBLEMA PONTOS DE FENO uri1261 
#include<bits/stdc++.h>
using namespace std;

int main(){

  map<string, int> preco;

  int palavras, num_tex;
  cin >> palavras >> num_tex;

  string str;
  int val;
  for(int i = 0; i < palavras; i++){
    cin >> str >> val;
    preco[str] = val;
  }

  for(int i = 0; i < num_tex; i++){
    int soma = 0;
    while(cin >> str, str!="."){
      soma = soma + preco[str];
    }
    cout << soma << endl;
  }
}
