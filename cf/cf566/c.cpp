#include<bits/stdc++.h>
using namespace std;

int n;
std::vector<string> v(100010);
pair < pair < int , char> , int > reduzido[100010];

vector<bool> esperando(1000100, 0);
vector<int> pos_esperando(1000100, 0);

vector<int> solucoes;

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  int cont;
  for(int i = 0;i < n ; i++){
    cont = 0;
    char last;
    for(int j = 0; j < v[i].size(); j++){
      if(v[i][j] == 'a' || v[i][j] == 'e' || v[i][j] == 'i' || v[i][j] == 'o' || v[i][j] == 'u' ){
        cont ++;
        last = v[i][j];
      }
    }
    //cout << last << endl;
    reduzido[i] = make_pair( make_pair(cont, last), i);
  }

  sort(reduzido, reduzido+n);
  // for(int i = 0; i < n ; i++){
  //   cout << "(" << reduzido[i].first.first << ", " << reduzido[i].first.second << ") --- " << reduzido[i].second << endl;
  // }

  queue< pair < pair < int , char> , int > > finais;
  queue < int > comecos;

  for(int i = 0; i < n; i++){
    if( i < n-1 && reduzido[i].first == reduzido[i+1].first){
      finais.push(reduzido[i]);
      finais.push(reduzido[i+1]);
      i++;
    }else{
      if(!esperando[ reduzido[i].first.first ]){
        esperando[ reduzido[i].first.first ] = true;
        pos_esperando[ reduzido[i].first.first ] = reduzido[i].second;
      }else{
        comecos.push(reduzido[i].second);
        comecos.push(pos_esperando[reduzido[i].first.first]);
        esperando[ reduzido[i].first.first ] = false;
      }
    }
  }
  //
  // cout << "finais" << endl;
  // while(!finais.empty()){
  //   cout << finais.front().first.first << " " << finais.front().first.second << endl;
  //   finais.pop();
  // }
  //
  // cout << "comecos " << endl;
  // while(!comecos.empty()){
  //   cout << v[comecos.front()] << endl;
  //   comecos.pop();
  // }

  while( finais.size() >= 2 && comecos.size() >=2){
    //cout << v[comecos.front()] << " " << v[finais.front().second] << endl;
    solucoes.push_back(comecos.front());
    solucoes.push_back(finais.front().second);
    comecos.pop(); finais.pop();
    //cout << v[comecos.front()] << " " << v[finais.front().second] << endl;
    solucoes.push_back(comecos.front());
    solucoes.push_back(finais.front().second);
    comecos.pop(); finais.pop();
  }

  while(finais.size() >= 4){
    solucoes.push_back(finais.front().second);
    finais.pop();
    int a = finais.front().second;
    finais.pop();
    solucoes.push_back(finais.front().second);
    solucoes.push_back(a);
    finais.pop();
    solucoes.push_back(finais.front().second);
  }
  //cout << "vao vir as solucoes" << endl;
  cout << solucoes.size()/4 << endl;
  for(int i = 0; i < solucoes.size(); i+=4){
    cout << v[solucoes[i]] << " " << v[solucoes[i+1]] << endl;
    cout << v[solucoes[i+2]] << " " << v[solucoes[i+3]] << endl;
  }






}
