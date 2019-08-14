#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t; cin >> t;
  while(t--){

    ll bateria, turnos, a, b;
    cin >> bateria >> turnos >> a >> b;

    ll lo = 0, hi = turnos, mid;
    ll ans = -1;
    while(lo <= hi){
      mid = lo + ((hi-lo)/2LL);
      // cout << "chute: " << mid << endl;
      // cout << "bateria que sobra: " << (bateria - (mid*a) - ((turnos - mid)*b)) << endl << endl;
      if( (bateria - (mid*a) - ((turnos - mid)*b)) > 0LL){
        ans = mid;
        lo = mid+1LL;
      }else{
        hi = mid-1LL;
      }

    }
    cout << ans << endl;


  }

}
