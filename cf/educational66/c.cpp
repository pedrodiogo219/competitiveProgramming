#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t; cin >> t;

  long long int n, k, aux;
  std::vector< long long int> v;
  std::vector<int> dist;
  while(t--){
    long long int sum = 0;
    cin >> n >> k;

    for(int i=0;i<n;i++){
      cin >> aux;
      v.push_back(aux);
    }

    int menor = 1000000000;
    int ind;
    for(int i=0; i+k < n; i++){
      //cout << "to olhando do " << v[i] << " até o " << v[k+i] << "   dist: " << v[k+i]-v[i] << endl;
      if(v[k+i] - v[i] < menor){
        menor = v[k+i] - v[i];
        ind = v[i];
      }
    }

    cout << ind + menor/2 << endl;
    v.clear();
  }
}
