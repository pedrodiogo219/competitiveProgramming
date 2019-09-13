//######### PASSWORD #########
// achar a maior substring que é prefixo, sufixo
// e aparece no meio da string ao mesmo tempo

#include<bits/stdc++.h>
using namespace std;

string s;
int p[1000100];
int vis[1000100];

void kmp(){
  p[0] = 0;
  for(int i = 1; i < s.size(); i++){
    p[i] = p[i-1];
    while(s[i] != s[p[i]] && p[i]) p[i] = p[p[i]-1];
    if(s[i] == s[p[i]]) p[i]++;
    if(p[i]!=0) vis[p[i]]++;
  }
}

int sol(){
  int i = s.size()-1;
  int x = p[i];

  if(vis[x]>= 2) return x;

  x = p[x-1];
  while(x){
    if(x!=0) vis[x]++;
    if(vis[x]>= 2) return x;
    x = p[x-1];
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> s;

  kmp();

  int ans = sol();

  if(ans==-1){
    cout << "Just a legend" << endl;
  }else{
    for(int i = 0; i < ans; i++){
      cout << s[i];
    }cout << endl;
  }


}
