#include<bits/stdc++.h>
using namespace std;
int n, m;

string s[550];

bool existe(int i, int j){
  return (i>=0) && (j>= 0) && (i < n) && (j < m) && (s[i][j] == '*');
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  long long marcadas = 0;

   cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> s[i];
    for(auto c : s[i]){
      if(c == '*') marcadas++;
    }
  }


  // for(int i=0; i < n ; i++){
  //   for(int j  =0; j < m ; j++){
  //     printf("%c", s[i][j]);
  //   }
  //   printf("\n");
  // }

  long long passei = 1;
  for(int i = 0; i < n; i++){
    for(int j =0; j < m ; j++){

      if(s[i][j] == '*'){
        if(existe(i-1, j) && existe(i, j-1) && existe(i+1, j) && existe(i, j+1)){
          //cout << "centro: (" << i << ", " << j << ")" << endl;
          int k = i;
          while(k > 0){
            k--;
            if(s[k][j] != '*') break;
            else passei++;
          }

          k = j;
          while(k > 0){
            k--;
            if(s[i][k] != '*') break;
            else passei++;
          }

          k = i;
          while(k < n-1){
            k++;
            if(s[k][j] != '*') break;
            else passei++;
          }
          k = j;
          while(k < m-1){
            k++;
            if(s[i][k] != '*') break;
            else passei++;
          }

          if(passei == marcadas) cout << "YES" << endl;
          else cout << "NO" << endl;

          return 0;
        }
      }

    }
  }

  cout << "NO" << endl;
  //cout << "passei: " << passei << " marcadas: " << marcadas << endl;



}
