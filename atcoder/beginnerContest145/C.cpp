#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

ii cidades[8];

long long D(ii a, ii b){

  return ((a.first - b.first)*(a.first - b.first)) + ((a.second - b.second)*(a.second - b.second));
}

int n, m;
int main(){
  iosbase;
  tie;

  int n, a, b; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    cidades[i] = {a, b};
  }
  sort(cidades, cidades+n);
  double acum = 0.0;
  int cont = 0;
  do{
    double dist = 0.0;
    for(int i = 1; i < n; i++){
      dist+=sqrt( D(cidades[i], cidades[i-1]) );
    }

    acum += dist;
    cont++;
  }while( next_permutation(cidades, cidades+n) );

  double total = acum / (double) cont;
  cout << setprecision(10) << fixed << total << endl;
}
