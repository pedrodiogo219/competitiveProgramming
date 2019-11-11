#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

long long int n, m;


vector<long long int> fatores;
int main(){
  iosbase;
  tie;

  cin >> n;
  m = n;
  int cont = 0;
  for(long long int i = 2; i * i <= n; i++){
    if(n % i == 0){
      fatores.push_back(i);
      cont++;
      while(n%i == 0) n/=i;
    }

    if(cont > 2) break;
  }

  if(n != 1LL){
    cont++;
    fatores.push_back(n);
  }

  if(cont == 0) cout << m << endl;
  else if(cont == 1) cout << fatores[0] << endl;
  else cout << "1" << endl;
}
