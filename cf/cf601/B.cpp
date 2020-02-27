#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

long long int vet[1010];

int n, m;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){
    cin >> n >> m;
    long long sum = 0;
    for(int i = 0; i < n; i++){
      cin >> vet[i];
      sum+=vet[i];
    }

    if( m < n || n <= 2 ){
      cout << "-1" << endl;
    }else{

      cout << 2*sum << endl;
      for(int i = 1; i < n; i++){
        cout << i << " " << i+1 << endl;
      }
      cout << n << " " << "1" << endl;


    }
  }
}
