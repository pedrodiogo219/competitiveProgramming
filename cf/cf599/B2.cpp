#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
string S, T;
int main(){
  iosbase;
  tie;

  int t; cin >> t;
  while( t--){

    int visS[30];
    int visT[30];

    for(int i = 0; i < 26; i++){
      visS[i] = 0;
      visT[i] = 0;
    }

    cin >> n;
    cin >> S;
    cin >> T;

    for(int i = 0; i < n; i++){
      visS[ S[i] - 'a']++;
      visT[ T[i] - 'a']++;
    }

    bool possible = true;
    for(int i = 0; i <26; i++){
      if( (visS[i] + visT[i]) & 1){
        possible = false;
        break;
      }
    }

    if(!possible){
      cout << "No" << endl;
      continue;
    }

    cout << "Yes" << endl;

    vector<ii> trocas;

    int j;
    for(int i = 0; i < n; i++){
      if(S[i]!=T[i]){
        // cout << S[i] << " e difernte de " << T[i] << endl;
        if(visS[S[i]-'a'] > 1){
          for(j = i+1; j < n; j++){
            if(S[j] == S[i]) break;
          }

          trocas.push_back({j, i});

          visS[S[i]-'a'] -= 2;
          visT[T[i]-'a'] --;
          visS[T[i]-'a'] ++;
          char aux = S[j];
          S[j] = T[i];
          T[i] = S[j];

        }
        else{
          // cout << "entrou aqui" << endl;
          for(j = i+1; j < n; j++){
            if(T[j] == S[i]) break;
          }

          trocas.push_back({j, j});
          trocas.push_back({j, i});


          visT[S[j] - 'a']++;
          visS[S[j] - 'a']--;

          visS[T[i] - 'a']++;
          visT[T[i] - 'a']--;

          swap(S[j], T[j]);
          swap(S[j], T[i]);

          visS[S[i]-'a']--;
          visT[T[i]-'a']--;
        }
      }else{
        visS[S[i]-'a']--;
        visT[T[i]-'a']--;
      }
    }

    cout << trocas.size() << endl;
    for(int i = 0; i < trocas.size(); i++){
      cout << trocas[i].first+1 << " " << trocas[i].second+1 << endl;
    }


  }
}
