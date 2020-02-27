#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

priority_queue<int> fila;

int n, m, k, q, x;
int main(){
  iosbase;
  tie;

  cin >> n >> x;

  for(int i = 0; i < n; i++){
    cin >> q;
    fila.push(q);
  }

  int topo = 0;
  while(x>0){
    topo = fila.top();
    fila.pop();

    // debug(topo);
    topo/=2;
    fila.push(topo);
    x--;
  }

  long long sum = 0;
  while(!fila.empty()){
    sum+= (1LL) * ((long long) fila.top());
    fila.pop();
  }

  cout << sum << endl;


}
