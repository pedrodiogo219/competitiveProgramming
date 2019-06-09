#include<bits/stdc++.h>
using namespace std;

#define mp(a, b) make_pair(a,b)

int tamanho_da_tree;
std::vector<int> st(400100, 0);

void updateST(int p, int L, int R, int i, int v){
  if( i < L || R < i ) return;

  if( L == i && R == i) {
    st[p] = v;
    return;
  }

  int next = p << 1;
  int mid = (L + R)>>1;

  updateST(next, L, mid, i, v);
  updateST(next+1, mid+1, R, i, v);
  st[p] = max(st[next], st[next+1]);
}

int queryST(int p, int L, int R, int i, int j){
  if(i > R || j < L) return 0;
  if(i <= L && R <= j) return st[p];

  int next = p << 1;
  int mid  = (L+R)>>1;

  int p1 = queryST(next, L, mid, i, j);
  int p2 = queryST(next+1, mid+1, R, i, j);

  return max(p1, p2);
}


struct no{
  int quant, num;
  no * nxt[26];

  no(){
    quant = 0; num = 0;
    for(int i=0;i<26;i++) nxt[i] = NULL;
  }

  void _insere(string &s, int pos){
    if(pos >= s.size()) return;
    int p = s[pos] - 'a';
    if(nxt[p] == NULL) nxt[p] = new no();
    nxt[p]->_insere(s, pos+1);
  }


  void destroy(){
    for(int i=0;i<26;i++){
      if(nxt[i] != NULL){
        nxt[i]->destroy();
        free(nxt[i]);
      }
    }
  }

  void insere(string &s, int pos){
    if(pos >= s.size()) return;
    int p = s[pos] - 'a';
    nxt[p]->quant++;
    updateST(1, 1, tamanho_da_tree, nxt[p]->num, nxt[p]->quant);
    nxt[p]->insere(s, pos+1);
  }

  void deleta(string &s, int pos){
    if(pos >= s.size()) return;
    //if(s == "") return;

    int p = s[pos] - 'a';
    nxt[p]->quant--;
    updateST(1, 1, tamanho_da_tree, nxt[p]->num, nxt[p]->quant);
    nxt[p]->deleta(s, pos+1);
  }

};

void printa( no * root, int nivel){
	for(int i=0;i<26;i++){
		if(root->nxt[i] != NULL){
			printf("to indo pro node: %c  nivel: %d  num: %d  quant: %d\n", 'a'+i, nivel+1, root->nxt[i]->num, root->nxt[i]->quant);
			printa(root->nxt[i], nivel+1);
			printf("voltei um nivel\n");
		}
	}

}

std::vector< int > limites;
int marca_vertices(no * root){
  queue < pair<no*, int> > fila;
  int cont = 0, nivel = 0;

  root->num = 0;
  limites.push_back(0);
  fila.push(mp(root, 0));

  while(!fila.empty()){
    no * atual = fila.front().first;
    int novo_nivel = fila.front().second;
    fila.pop();


    if(novo_nivel!=nivel){
      limites.push_back(cont);
      nivel = novo_nivel;
    }

    atual->num = cont++;
    //cout << "atual:   num: " << atual->num << " novo_nivel: " << novo_nivel << endl;
    for(int i=0;i<26;i++){
      if(atual->nxt[i] != NULL){
        fila.push(mp(atual->nxt[i], novo_nivel+1));
      }
    }
  }
  limites.push_back(cont);
  return cont-1;
}


std::vector<string> ss(100100);
std::vector<int> tipo(100100);
std::vector<int> k(100100), l(100100), d(100100);

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int Q; cin >> Q;
  int op, pos;
  string s;
  for(int q = 1; q <= Q; q++){
    cin >> op;

    switch (op) {
      case 1:
        cin >> s;
        tipo[q] = 1;

        reverse(s.begin(), s.end());
        ss[q] = s;
        break;
      case 2:
        cin >> k[q] >> l[q];
        tipo[q] = 2;
        break;

      case 3:
        tipo[q] = 3;
        cin >> d[q];
        break;

    }
  }


  no * root = new no();
  for(int q = 0; q <= Q; q++){
    if(tipo[q] == 1){
      root->_insere(ss[q], 0);
    }
  }

  //printa(root, 0);

  tamanho_da_tree = marca_vertices(root);

  /*cout << "tamanho: " << tamanho_da_tree << endl;
  for(int i=0;i<limites.size();i++){
    cout << i << " ";
  }
  cout << endl;
  for(int i=0;i<limites.size();i++){
    cout << limites[i] << " ";
  }
  cout << endl;
  */


  for(int q=1; q<=Q;q++){
    if(tipo[q] == 1){
      root->insere(ss[q], 0);
    }
    if(tipo[q] == 3){
      root->deleta(ss[d[q]], 0);
      ss[d[q]] = "";
    }
    if(tipo[q] == 2){
      //consultar a segtree
      int meuI, meuJ;

      if(l[q] >= limites.size() || l[q]+1 >= limites.size()){
        cout << "NO" << endl;
      }else{
        meuI = limites[ l[q] ];
        meuJ = limites[l[q]+1] - 1;
        int Kcalculado = queryST(1, 1, tamanho_da_tree, meuI, meuJ);
        //cout << "Kcalculado: " << Kcalculado << endl;
        if (Kcalculado >= k[q]) cout << "YES" << endl;
        else cout << "NO" << endl;
      }
    }
  }
  //printa(root, 0);


  root->destroy();
}
