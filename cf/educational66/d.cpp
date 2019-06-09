#include<bits/stdc++.h>
using namespace std;

int n, k;
int v[300100];
long long int INF = 100000000000000;

long long dp(int pos, int cortes){
  cout << "pos: " << pos << endl;
    if(pos == n){
      if(cortes > 0) return -INF;
      return 0;
    }

    long long sumPegando = v[pos] * (k - cortes);
    long long sumCortando = v[pos] * (k - cortes);

    
    sumPegando += dp(pos+1, cortes);
    if(cortes>1)
      sumCortando += dp(pos+1, cortes - 1);
    else
      sumCortando += -INF;

    cout << "se eu pegar o " << v[pos] << " eu fico com " << sumPegando << endl;
    cout << "se eu cortar depois do " << v[pos] << " eu fico com" << sumCortando << endl << endl << endl;
    return max( sumCortando, sumPegando);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for(int i=0;i<n;i++){
    cin >> v[i];
  }

  cout << dp(0, k-1) << endl;
}
