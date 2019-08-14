#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int vet[101000];
int faltas[101000];

int n, m;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> vet[i];

    int ans = 0;

    for(int i = 0; i < n; i++){
      cin >> faltas[i];
      ans = max(ans, vet[i]*20 - faltas[i]*10);
    }
    cout << ans << endl;


  }
}
