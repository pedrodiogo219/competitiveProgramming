
#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  unsigned long long int n, k;
  int t;
  cin >> t;
  while(t--){
    unsigned long long int ans = 0;
    cin >> n >> k;


    while(n>0){
        if(n % k != 0){
          ans += n%k;
          n -= n%k;
        }
        else{
          ans+=1;
          n /= k;
        }
      }

      cout << ans << endl;

    }


}
