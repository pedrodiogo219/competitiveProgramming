#include<bits/stdc++.h>
using namespace std;


struct no{
  int quant;
  struct no* filhos[2];

  no(){
    quant = 0;
    filhos[0] = NULL;
    filhos[1] = NULL;
  }

  void insere(int x, int pos=31){
    if(pos < 0) return;

    struct no* atual;
    if( x & (1<<pos) ){
      if(filhos[1] == NULL) filhos[1] = new no();
      atual = filhos[1];
    }else{
      if(filhos[0] == NULL) filhos[0] = new no();
      atual = filhos[0];
    }

    atual->quant+=1;
    atual->insere(x, pos-1);
  }

  int consulta(int x, int pos=31, int val=0){
    if(pos < 0) return val;

    bool bit = (( x & (1<<pos)) > 0 );

    if(filhos[!bit] != NULL && filhos[!bit]->quant > 0){
      filhos[!bit]->consulta(x, pos-1, val+(1<<pos));
    }
    else{
      filhos[bit]->consulta(x, pos-1, val);
    }
  }

  void remove(int x, int pos=31){
    if(pos < 0) return;

    struct no * atual;
    if( x & (1 << pos)){
      atual = filhos[1];
    }else{
      atual = filhos[0];
    }

    atual->quant--;
    atual->remove(x, pos-1);

  }

  void printa(string s){
    //printf("entrou aqui\n");
    if(filhos[0] != NULL and filhos[0]->quant > 0){
      filhos[0]->printa(s+'0');
    }
    if(filhos[1]!=NULL and filhos[1]->quant > 0){
      filhos[1]->printa(s+'1');
    }
    if(filhos[0] == NULL and filhos[1] == NULL){
      for(int i=0; i < quant; i++) cout << s << endl;
    }
  }


};


int main(){
    int n; scanf("%d", &n);
    char c; int x;
    struct no * raiz = new struct no;
    raiz->insere(0);
    while(n--){
      getchar();
      scanf("%c %d", &c, &x);
      //printf("c: %c,  x: %d\n", c, x);

      if(c=='+') raiz->insere(x);
      if(c=='-') raiz->remove(x);
      if(c=='?') printf("%d\n", raiz->consulta(x));
      //if(c=='p') raiz->printa("");

    }
}
