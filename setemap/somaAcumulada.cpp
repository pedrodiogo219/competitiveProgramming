#include<bits/stdc++.h>
using namespace std;

int vet[1000100];

int main(){

  int n; cin >> n;
  for(int i = 1; i <=n; i++){
    cin >> vet[i];
    vet[i]+=vet[i-1];
  }
  int q; cin >> q;
  int E, D;
  while(q--){
    cin >> E >> D;
    cout << vet[D+1] - vet[E] << endl;
  }
}
