//######## GAME OF MATCHINGS ##########
// awawww
// 3
// 10 21 10
// ---------------
// 2


#include<bits/stdc++.h>
using namespace std;
#define INF 10000000
int n, cont = 0;
int p[500100];
int pattern[500100];
int txt[500100];
string s;

int vis[30];
int last[30];

void kmp(){
  p[0] = 0;
  for(int i = 1; i < n; i++){
    p[i] = p[i-1];
    while(true){
      if(p[i] == 0) break;
      if( pattern[p[i]] == -1){
        if(pattern[i] > p[i]) break;
      }
      if(!(pattern[ p[i] ] != pattern[i])) break;
      p[i] = p[p[i]-1];
    }

    if(pattern[p[i]] == pattern[i] || (pattern[p[i]] == -1 && pattern[i] > p[i])) p[i]++;
  }

  int j = 0;
  j = p[0];
  for(int i = 0; i < s.size(); i++){
    while( txt[i] != pattern[j] && !(pattern[j] == -1 && txt[i] > j) && j){
      j = p[j-1];
    }
    if(pattern[j] == txt[i] || (pattern[j] == -1 && txt[i] > j)) j++;
    if(j>=n){
      cont++;
      j = p[j-1];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  memset(vis, -1, sizeof vis);
  memset(last, -1, sizeof last);

  int x;
  cin >> s;
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> x;
    if(vis[x] == -1) pattern[i] = -1;
    else pattern[i] = i - vis[x];
    vis[x] = i;
  }

  pattern[n] = INF;

  for(int i = 0; i < s.size(); i++){
    if(last[s[i]-'a'] == -1) txt[i] = -1;
    else txt[i] = i - last[s[i]-'a'];
    last[s[i] -'a'] = i;
  }

  kmp();
  cout << cont << endl;
}
