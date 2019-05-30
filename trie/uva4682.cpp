#include<bits/stdc++.h>
using namespace std;


struct node{

    node * filhos[2];

    node(){
      filhos[0] = filhos[1] = NULL;
    }

    void insere(int x, int p){
      if(p < 0) return;
      bool bit = x & (1 << p);
      if(filhos[bit]==NULL){
        filhos[bit] = new node();
      }
      filhos[bit]->insere(x, p-1);
    }

    int consulta(int x, int p){
      if(p < 0) return 0;

      bool bit = x & (1 << p);
      if(filhos[!bit] != NULL){
          int res = filhos[!bit]->consulta(x, p-1);
          res = res | (1 << p);
          return res;
      }
      else if(filhos[bit] != NULL){
          int res = filhos[bit]->consulta(x, p-1);
          res = res &(~(1 << p));
          return res;
      }
      else{
        cout << "aqui foi o " << x << endl;
        return 0;
      }
    }

    void destroy(){
      if(filhos[0]!=NULL){
        filhos[0]->destroy();
        free(filhos[0]);
      }
      if(filhos[1]!=NULL){
        filhos[1]->destroy();
        free(filhos[1]);
      }
    }

    /*
    void printa(int p){
      if(p < 0) return;

      for(int i=0;i<2;i++){
        if(filhos[i]!=NULL){
          cout << ""
        }
      }
    }*/
};

int main(){
  int t; cin >> t;
  while(t--){
    node * trie = new node();
    trie->insere(0, 31);
    int n, a; cin >> n;
    int ans = 0, acumulado = 0;
    for(int i=0;i<n;i++){
      cin >> a;
      acumulado = acumulado^a;
      int res = trie->consulta(acumulado, 31);
      ans = max(ans, res);
      trie->insere(acumulado, 31);

      //cout << "acabei de ler o: " << a << endl;
      //cout << "acumulado: " << acumulado << endl;
      //cout << "res: " << res << endl;

    }
    trie->destroy();
    cout << ans << endl;
  }
}
