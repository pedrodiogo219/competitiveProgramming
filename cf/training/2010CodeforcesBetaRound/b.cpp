#include<bits/stdc++.h>
using namespace std;

bool is_digit(char c){
  return c>='0' && c<='9';
}
bool is_letter(char c){
  return (c >= 'A' && c<= 'Z');
}

long long int pot26[100000];
long long int pot10[100];


string solve(string &s){
  bool comecouNumeros = false;
  bool caso1 = false, caso2 = true;
  int pos = -1;
  for(int i = 0; i < s.size(); i++){
    if(!comecouNumeros && is_digit(s[i])){
      comecouNumeros = true;
      pos = i;
      continue;
    }

    if(comecouNumeros && is_letter(s[i])){
      caso1 = true;
      caso2 = false;
    }
  }

  string saida = "";


  if(caso2){
    int cont = 0;
    long long int coluna = 0;
    for(int i = pos-1; i >= 0; i--){
      coluna += (s[i]-'A'+1) * pot26[cont];
      cont++;
    }

    saida+= 'R';
    for(int i = pos; i < s.size(); i++){
      saida += s[i];
    }
    saida+= 'C';
    saida+= to_string(coluna);
  }

  else if(caso1){
    long long coluna = 0;
    int cont = 0;
    for(int i = s.size()-1; i >=0; i--){
        if(s[i] == 'C'){
          pos = i;
          break;
        }
        coluna+= (s[i]-'0') * pot10[cont];
        cont++;
    }


    string Scol = "";

    while(coluna>0){
      if(coluna%26 == 0){
          Scol+='Z';
          coluna -= 26;
      }
      else{
        Scol+= ((coluna%26) + 'A' - 1);
        coluna -= coluna%26;
      }
      coluna/=26;
    }


    for(int i = Scol.size()-1; i >= 0; i--){
      saida+= Scol[i];
    }
    for(int i = 1; i < pos; i++){
      saida+= s[i];
    }
  }
  return saida;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  pot10[0] = 1;
  for(int i = 1; i <= 7; i++){
    pot10[i] = pot10[i-1] * 10;
  }


  pot26[0] = 1;
  for(int i = 1; i<100000 ; i++){
    if(pot26[i-1] > 1000000) break;
    pot26[i] = pot26[i-1] * 26;
  }

  int n; cin >> n;
  string s;

  while(n--){
    cin >> s;
    cout << solve(s) << endl;

  }
}
