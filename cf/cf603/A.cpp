#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define T int t; cin >> t; while( t--)

long long int vet[10];

int n, m;
int main(){
  iosbase;
  tie;

  T{
    for(int i = 0; i < 3; i++){
      cin >> vet[i];
    }

    sort(vet, vet+3);

    long long int dif = vet[2] - vet[1];

    if(dif >= vet[0]){
      cout << vet[0] + min(vet[1], vet[2]-vet[0]) << endl;
    }else{

      vet[0] -= dif;
      vet[2] = vet[1];

      cout << vet[1] + (vet[0]/2) + dif << endl;

    }


  }

}
