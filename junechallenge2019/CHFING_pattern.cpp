#include<bits/stdc++.h>
using namespace std;

bool v[11000];
int mod[1000];

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie();
  // cout.tie();

  int t; cin >> t;
  while(t--){
    memset(v, 0, sizeof(v));
    memset(mod, 0, sizeof(mod));
    int n, k;
    cin >> n >> k;
    //cout << n << " " << k << endl;

    for(int i = k; i <= k+n-1; i++){
      v[i] = 1;
    }

    for(int i = k; i < 10000; i++){
      for(int j = k; j <= k+n-1; j++){
        int pos = i;
        if(v[pos])
        while(pos < 10000){
          pos+=j;
          v[pos] = 1;
        }
      }

    }

    int cont = 0;
    for(int i = 1; i < 10000; i++){
      if(v[i] == 0) {
        cont++;
        if(i>=k)
        mod[ i%k ]++;
      }
    }

    //
    // for(int i = 1; i < 50; i++){
    //   printf("%2d ", i);
    // }
    // cout << endl;
    // for(int i = 1; i < 50; i++){
    //   printf("%2d ", v[i]);
    // }cout << endl;
    //
    // for(int i = 0; i < k; i++){
    //   cout << "mod " << i << ": " << mod[i] << endl;
    // }

    cout << cont;
    //cout << " " << cont - k + 1;
    cout << endl;


    // int vezes = n-1;
    // int comprimento = k - n;
    // int parte = comprimento / vezes;
    // int resto = comprimento % vezes;
    //
    // int soma = (((1 + parte)*parte) / 2)*vezes;
    // //cout << "prim " << soma << endl;
    // //cout << "outra " << resto * (parte+1) << endl;;
    // soma += resto * (parte+1);
    // //cout << "comeco " << k-1 << endl;
    // cout << soma + k - 1 << endl;
  }
}
