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

  string s;
  cin >> s;

  s = ' ' + s;
  bool flag = true;

  for(int i = 1 ; i < s.size(); i++){
    if(i & 1){
      if(s[i] == 'L') {
        flag = false;
        break;
      }
    }else{
      if(s[i] == 'R'){
        flag = false;
        break;
      }
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
