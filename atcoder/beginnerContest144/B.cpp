#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  for(int i = 1; i <= 9; i++){
    if(t%i == 0 && t/i >= 1 && t/i <= 9){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
