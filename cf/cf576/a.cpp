#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m, x, y;
int vet[1000100];
int main(){
  iosbase;
  tie;

  cin >> n >> x >> y;
  for(int i = 1 ; i <= n; i++){
    cin >> vet[i];
  }

  for(int i = 1; i <= n; i++){
    bool ans = true;

    for(int j = i-1, d = x; d>0 && j>0; d--, j--){
      if(vet[i] >= vet[j]){
        ans = false; break;
      }
    }

    for(int j = i+1, d = y; d>0 && j <= n; d--, j++){
      if(vet[i] >= vet[j]){
        ans = false; break;
      }
    }

    if(ans == true){
      cout << i << endl;
      return 0;
    }
  }


}
