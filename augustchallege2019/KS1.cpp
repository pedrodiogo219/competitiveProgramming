#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define MAXN 1048575+10

int n, m;
int vet[100100];

vector<long long int> vis[MAXN];

int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    cin >> n;
    vet[0] = 0;
    vis[0].push_back(0);
    for(int i = 1; i<=n; i++){
      cin >> vet[i];
      vet[i] = vet[i-1]^vet[i];
      vis[vet[i]].push_back(i);
    }

    long long int cont = 0;
    for(int i = 0; i <= MAXN-5; i++){
      if(vis[i].size() < 2) continue;
      long long int fator = -(vis[i].size()-1);
      for(int j = 0; j < vis[i].size(); j++){
        cont+=vis[i][j] * fator;
        fator+=2;
      }
      cont-= ((vis[i].size()-1)*vis[i].size()) / 2;
    }

    cout << cont << endl;
    for(int i = 0; i <= MAXN-5; i++){
      vis[i].clear();
    }
  }
}
