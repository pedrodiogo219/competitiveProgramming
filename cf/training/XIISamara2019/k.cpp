#include<bits/stdc++.h>
using namespace std;

string s;
vector<char> cor;

bool checa(){
  char p1 = 'Z';
  char p2 = 'Z';
  bool ans = true;
  char c;
  for(int i = 0; i < s.size(); i++){
    c = s[i];

    if( c == cor[0] ){
      if( p1 == cor[1] ){
        ans = false;
        break;
      }
    }

    if(c == cor[2]){
      p2 = cor[2];
    }

    if(c == cor[1]){
      if( p2!= cor[2]){
        p2 = cor[1];
      }
      else{
        p1 = cor[1];
      }
    }

  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  cin >> s;

  cor.push_back('B');
  cor.push_back('G');
  cor.push_back('R');

  bool ans = false;
  do{
    if( checa() ){
      ans = true;
      break;
    }
  }while( next_permutation(cor.begin(), cor.end()) );

  if(ans) printf("YES\n");
  else printf("NO\n");

}
