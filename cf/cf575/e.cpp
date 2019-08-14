#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int > ii;
int b, p;

vector< ii > brancos;
vector< ii > pretos;

int main(){
  int t; cin >> t;
  while(t--){
    cin >> p >> b;
    bool inverte = false;
    if (b < p){
      swap(b, p);
      inverte = true;
    }

    int i;
    for(i = 2; p > 0; i++){
      if(i %2 == 0){
        b--;
        brancos.push_back(make_pair(i, 2));
      }
      else{
        p--;
        pretos.push_back(make_pair(i, 2));
      }
    }
    if(b > 0){
      brancos.push_back(make_pair(i, 2));
      b--;
    }

    if( ceil(b/2.0) > pretos.size()  ) cout << "NO" << endl;
    else{

      for(ii eu : pretos){

        if(b==0) break;
        brancos.push_back( make_pair(eu.first, eu.second+1));
        b--;

        if(b == 0) break;
        brancos.push_back( make_pair(eu.first, eu.second-1));
        b--;
      }


      if(inverte){
        for(int j = 0; j < brancos.size(); j++){
          brancos[j].second++;
        }

        for(int j = 0; j < pretos.size(); j++){
          pretos[j].second++;
        }
      }
      cout << "YES" << endl;
      // if(inverte) cout << "inverteu" << endl;
      // else cout << "nao inverteu" << endl;
      // cout << "brancos:" << endl;
      for(ii eu: brancos){
        cout << eu.first << " " << eu.second << endl;
      }
      // cout << "pretos:" << endl;
      for(ii eu: pretos){
        cout << eu.first << " " << eu.second << endl;
      }
    }

    brancos.clear();
    pretos.clear();

  }
}
