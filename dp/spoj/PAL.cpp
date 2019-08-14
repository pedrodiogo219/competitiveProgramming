#include<bits/stdc++.h>
using namespace std;

#define INF 1e17

string s;
int mpal[2010][2010];

bool is_palindrome(int i, int j){
  if(i>j || i==j) return true;

  if(mpal[i][j] != -1) return mpal[i][j];

  bool result = false;
  if(s[i] == s[j]){
    result = is_palindrome(i+1, j-1);
  }
  return mpal[i][j] = result;
}


long long int memo[2100];

void processa(){
  for(int i = 0; i<s.size(); i++){
    memo[i] = INF;
  }

  for(int i = 0; i < s.size(); i++){
    if(is_palindrome(0, i)){
      memo[i] = 1;
    }else{
      for(int k = 1; k <= i; k++){
        if(is_palindrome(k, i)){
          memo[i] = min(memo[i], memo[k-1]+1);
        }
      }
    }

  }

}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n, casos = 0;
  while(cin >> n, n!=0){
    casos++;
    memset(mpal, -1, sizeof(mpal));
    cin >> s;
    processa();
    cout << "Teste " << casos << endl;
    cout << memo[n-1] << endl<< endl;
  }
}
