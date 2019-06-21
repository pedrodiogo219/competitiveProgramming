#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n; cin >> n;
  if(n == 1) cout << '1' << endl;
  else{
    int som = 1;
    for(int i = 2; i <= n; i++){
      som += (i-1)*4;


    }
    cout << som << endl;

  }

}
