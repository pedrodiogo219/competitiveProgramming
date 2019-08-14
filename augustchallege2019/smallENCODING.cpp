#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

ll dezElevadoA[100100];
void preProcess(){
  dezElevadoA[0] = 1;
  for(int i = 1; i < 100010; i++){
    dezElevadoA[i] = (dezElevadoA[i-1] * 10LL) % MOD;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cerr.tie();

  preProcess();

  int t; cin >> t;
  ll lixo, L, R;
  while(t--){
    cin >> lixo >> L;
    cin >> lixo >> R;

    cout << sol_bruta(L, R) << endl;
  }

}
