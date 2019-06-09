#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  long long aux, x = 0;
  cin >> n;

  std::vector<long long> v;
  stack<long long> pilha;
  pilha.push(1LL);

  long long maximo = (1LL << 32) - 1LL;

  bool flag = false;
  string s;
  for(int i=0;i<n;i++){
    cin >> s;

    if(s == "for"){
      cin >> aux;
      v.push_back(aux);
    }

    if(s == "add"){
      if(v.size() > 0){
        for( int j = 0;j < v.size(); j++){

          if( pilha.top() * v[j]  > maximo){
            flag = true;
            break;
          }
          else{
              pilha.push( pilha.top() * v[j] );
          }
        }

        v.clear();
      }

      x+= pilha.top();
      if(x > maximo){
        flag = true;
        break;
      }
    }

    if(s == "end"){
      if(v.size() == 0 && pilha.size() > 1) pilha.pop();
      else v.pop_back();
    }
  }

  if(flag) cout << "OVERFLOW!!!" << endl;
  else cout << x << endl;


}
