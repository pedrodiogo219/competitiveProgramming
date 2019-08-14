#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
int att[100100];
int vet[100100], zom[100100];

int main(){
  iosbase;
  tie;
  int l, r;

  int t; cin >> t;
  while( t--){
    memset(att, 0, sizeof att);
    cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> vet[i];
      l = max(1, i - vet[i]);
      r = min(n, i + vet[i]);
      att[l]+=1;
      att[r+1]-=1;
    }
    int acc = 0;
    for(int i = 1; i <= n; i++){
      cin >> zom[i];
      acc+=att[i];
      vet[i] = acc;
    }

    // for(int i = 1; i <= n; i++){
    //   cout << vet[i] << " ";
    // }cout << endl;
    sort(vet+1, vet+n+1);
    sort(zom+1, zom+n+1);

    bool ans = true;
    for(int i = 1; i <= n; i++){
      if(vet[i]!=zom[i]) {
        ans = false;
        break;
      }
    }
    if(ans){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }

  }
}
