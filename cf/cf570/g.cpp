#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool compare(ii eu, ii outro){
  if(eu.first!=outro.first) return eu.first > outro.first;
  return eu.second > outro.second;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(); cout.tie();
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int aux, q;
    std::vector<int> quero(n+5, 0);
    std::vector<int> naoque(n+5, 0);
    for(int i = 0; i < n; i++){
      cin >> aux >> q;
      if(q) naoque[aux]++;
      else quero[aux]++;
    }

    vector<ii> v;
    for(int i = 0; i < quero.size(); i++){
      v.push_back(make_pair( naoque[i]+quero[i], naoque[i]));
    }

    sort(v.begin(), v.end(), compare);
    for(auto a: v){
      cout << "(" << a.first << " " << a.second << ")" << "  ";
      cout << endl;
    }
    int freq = v[0].first;
    int ult = freq+1;
    long long somaTotal = 0, sominha = 0;
    for(int i = 0; i < v.size(); i++){
      freq = min(freq, v[i].first);
      if(freq == 0) break;
      somaTotal+=freq;
      sominha+= min(freq, v[i].second);
      freq--;
    }
    cout << somaTotal << " " << sominha << endl;

  }

}
