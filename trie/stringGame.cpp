//https://codeforces.com/contest/455/problem/B
#include<bits/stdc++.h>
using namespace std;

struct no{
  no * filhos[26];
  no(){
    for(int i=0;i<26;i++) filhos[i] = NULL;
  }

  void insere(string &s, int pos){
    if(pos < s.size()){ //pos ta dentro da string ainda
      int p = s[pos] - 'a';
      if(filhos[p] == NULL){
        filhos[p] = new no();
      }
      filhos[p]->insere(s, pos+1);
    }
  }

  void destroy(){
    for(int i=0;i<26;i++){
      if(filhos[i] !=NULL) filhos[i]->destroy();
      free(filhos[i]);
    }
  }

  bool da_pra_ganhar(){
    for(int i=0;i<26;i++){
      if(filhos[i] != NULL && !filhos[i]->da_pra_ganhar()){
        return true;
      }
    }
    return false;
  }

};

int main(){
  int n, k;
  cin >> n >> k;

  no * trie = new no();
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    trie->insere(s, 0);
  }

  if(trie->da_pra_ganhar())
    if(k%2==1)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  else
    cout << "Second" << endl;
  trie->destroy();
}
