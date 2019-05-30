#include<bits/stdc++.h>
using namespace std;

int vet[1000100];
int res[1000100];

int main(){
  int t; cin >> t;
  while(t--){

    int n, x; cin >> n >> x;
    vet[0] = 0;
    for(int i=1;i<=n;i++){
      cin >> vet[i];
      vet[i]+=vet[i-1];
    }

    for(int i=1;i<=n;i++){
      res[i] = 0;
      if(vet[i]!=vet[i-1]){ // quer dizer que to no 1
        int qnt;
        if(i > x)
          qnt = x - vet[i-1] + vet[i-x-1];
        else
          qnt = (i-1) - vet[i-1] + vet[0];

        int pos = i-qnt;
        cout << "quantidade de zeros antes: " << qnt << endl;
        cout << "posicao que o 1 vai: " << pos << endl << endl;
        res[pos] = 1;
      }
    }

    cout << res[1];
    for(int i=2;i<=n;i++){
      cout << " " << res[i];
    }
    cout << endl;

  }
}
