#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, k;
string s;
string pattern1 = "RGB";
string pattern2 = "GBR";
string pattern3 = "BRG";

int cost(int L, int R){
  int cont1 = 0;
  int cont2 = 0;
  int cont3 = 0;

  for(int i = 0; i+L <= R ; i++){
    if( s[i+L] != pattern1[ (i%3) ] ) cont1++;
    if( s[i+L] != pattern2[ (i%3) ] ) cont2++;
    if( s[i+L] != pattern3[ (i%3) ] ) cont3++;
  }

  return min( cont1, min(cont2, cont3) );

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;
  while(t--){
    cin >> n >> k;
    cin >> s;

    int ans = INF;
    for(int i = 0; i+k-1 < n; i++){
      // cout << "intervalo: " << i << " " << i+k-1 << endl;
      ans = min(ans, cost(i, i+k-1));
    }
    cout << ans << endl;

  }

}
