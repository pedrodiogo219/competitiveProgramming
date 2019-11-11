#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
int main(){
  iosbase;
  tie;

  int n, k, a;
  cin >> n >> k;

  set<int> ss;
  deque<int> fila;
  int size = 0;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(size < k){
      if(ss.find(a) == ss.end()){
        ss.insert(a);
        fila.push_back(a);
        size++;
      }
    }
    else{
      // cout << "entrou aqui" << endl;
      if(ss.find(a)==ss.end()){
        int removido = fila.front();
        fila.pop_front();
        ss.erase(removido);
        ss.insert(a);
        fila.push_back(a);
      }
    }
  }

  cout << fila.size() << endl;
  while(!fila.empty()){
    int removido = fila.back();
    cout << removido << endl;
    fila.pop_back();
  }
}
