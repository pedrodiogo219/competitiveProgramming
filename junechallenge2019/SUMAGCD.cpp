#include<bits/stdc++.h>
using namespace std;


int n;
int aux;
int st[400100];
std::vector<int> v;
#define INF 100000000

int haha[100];

int calcula(int pos, int gcdA, int gcdB){
  if(pos == n){
    if(gcdA!=0 && gcdB!=0){
      return gcdA+gcdB;
    }
    else return -INF;
  }

  int pegaA;
  if(gcdA != 0)
    pegaA = calcula(pos+1, __gcd(gcdA, haha[pos]), gcdB);
  else
    pegaA = calcula(pos+1, haha[pos], gcdB);

  int pegaB;
  if(gcdB != 0)
    pegaB = calcula(pos+1, gcdA, __gcd(gcdB, haha[pos]));
  else
    pegaB = calcula(pos+1, gcdA, haha[pos]);

  return max(pegaA, pegaB);
}

void build(int pos, int L, int R){
  if(L>R) return;
  if(L == R){
    st[pos] = v[L];
    return;
  }

  int next = pos << 1, mid = L + ((R-L)/2);
  build(next, L, mid);
  build(next+1, mid+1, R);

  st[pos] = __gcd( st[next], st[next+1] );
  return;
}

int query(int pos, int L, int R, int i, int j){
  if(L > R) return 0;
  if(i <= L && R <= j) return st[pos];
  if(j < L || i > R) return 0;

  int next = pos << 1, mid = L + ((R-L)/2);

  int esq = query(next, L, mid, i, j);
  int dir = query(next+1, mid+1, R, i, j);

  if(esq == 0) return dir;
  else if(dir == 0) return esq;
  else return __gcd(esq, dir);

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;
  while(t--){
    cin >> n;
    // for(int i = 0; i < v.size(); i++){
    //   cout << v[i] << " ";
    // } cout << endl;
    if(n > 20){
      set<int> s;
      for(int i = 0; i < n ; i++){
        cin >> aux; s.insert(aux);
      }

      v.push_back(0);
      for(auto it = s.begin() ; it!=s.end(); ++it){
        v.push_back(*it);
      }

      build(1, 1, v.size()-1);
      // for(int i = 0; i < 4*n ; i++){
      //   cout << st[i] << " ";
      // } cout << endl;

      int maior_gcd = 0, r = v.size()-1;
      for(int i = 1; i < v.size(); i++){
        //cout << "estou no " << v[i] << endl;
        int esq = query(1, 1, r, 1, i-1);
        int dir = query(1, 1, r, i+1, r);
        //cout << "esq: " << esq << "  dir: " << dir << endl;

        int sol = 0;
        if(esq==0)       sol = dir;
        else if(dir==0)  sol = esq;
        else sol = __gcd(dir, esq);

        sol += v[i];
        maior_gcd = max(maior_gcd, sol);
      }
      cout << maior_gcd << endl;
      v.clear();
    }
    else{
      for(int i = 0; i < n ; i++){
        cin >> haha[i];
      }

      cout << calcula(0, 0, 0) << endl;
    }
  }
}
