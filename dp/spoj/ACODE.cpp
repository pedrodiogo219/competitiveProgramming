#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tam;
string s;

ll memo[5100];

ll dp(int pos){
  if(pos == tam){
    return 1;
  }

  if(memo[pos]!= -1 ) return memo[pos];

  ll soma = 0;

  if(s[pos] != '0'){
    soma+=dp(pos+1);
  }

  if(s[pos] == '1' && pos+1 < tam){
    soma+=dp(pos+2);
  }
  else if(s[pos] == '2' && pos+1 < tam && s[pos+1] <= '6'){
    soma+=dp(pos+2);
  }
  return memo[pos] = soma;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  while(cin >> s && s!="0"){
    memset(memo, -1, sizeof(memo));
    tam = s.size();
    cout << dp(0) << endl;
  }

}
