#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define T int t; cin >> t; while( t--)

string vet[20];

int vis[15];

int n, m;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while(t--){
    for(int i = 0 ; i < 10; i++) vis[i] = 0;
    int n; cin >> n;
    for(int i = 0 ; i < n; i++){
      cin >> vet[i];
      vis[vet[i][0] - '0'] ++;
    }

    int cont = 0;
    for(int i = 0; i < n ; i ++){
      for(int j = i+1; j < n; j++){

        if(vet[i] == vet[j]){
          for(int k = 0; k < 10; k++){
            if(vis[k] == 0){
              vis[k]++;
              vet[j][0] = k+'0';
              cont++;
              break;
            }
          }
        }
      }
    }

    cout << cont << endl;
    for(int i = 0; i < n; i++){
      cout << vet[i] << endl;
    }
  }



}
