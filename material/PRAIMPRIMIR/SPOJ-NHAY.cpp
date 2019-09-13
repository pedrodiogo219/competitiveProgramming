//######## SPOJ-NHAY ########
// stream-oriented kmp

#include<bits/stdc++.h>
using namespace std;

int p[1000100];
int n;
string pattern;
void kmp(){
  p[0] = 0;

  for(int i = 1; i < pattern.size(); i++){
    p[i] = p[i-1];
    while(pattern[i] != pattern[p[i]] && p[i] > 0) p[i] = p[p[i] - 1];
    if(pattern[i] == pattern[p[i]]) p[i]++;
  }

}


int main(){

  bool first = true;
  char c;
  while(scanf("%d ", &n)!=EOF){
    if(first) first = false;
    else printf("\n");

    getline(cin, pattern);
    kmp();
    int j = 0, pos = 0;
    while(scanf("%c", &c) && c!='\n'){
      while(j != 0 && c!=pattern[j]) j = p[j-1];
      if(c == pattern[j]){
        j++;
        if(j >= n){
          printf("%d\n", pos-n+1);
          j= p[j-1];
        }
      }
      pos++;
    }
  }
}
