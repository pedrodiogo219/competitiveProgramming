#include<bits/stdc++.h>
using namespace std;
#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

typedef long long ll;
string s;


struct pres{
  int vet[30];
  pres(){
    for(int i = 0; i < 26; i++) vet[i] = 0;
  }
  pres(char c){
    for(int i = 0; i < 26; i++) vet[i] = 0;
    vet[c - 'a']++;
  }

  int cont(){
    int soma = 0;
    for(int i = 0; i< 26; i++){
      soma+=vet[i];
    }
    return soma;
  }
};


pres junta(pres a, pres b){
  pres ans;

  for(int i = 0 ; i < 26; i++){
    if(a.vet[i] == 1 || b.vet[i] == 1) ans.vet[i] = 1;
  }

  return ans;
}

pres st[400100];

void build(ll pos, ll L, ll R){
  // cout << "L: " << L << "  R: " << R << endl;
  if(L == R){
    st[pos] = pres(s[L]);
    return;
  }

  ll next = pos << 1, mid = (L+R) >> 1 ;
  build(next, L, mid);
  build(next+1, mid+1, R);

  st[pos] = junta(st[next], st[next+1]);
}

void att(ll pos, ll L, ll R, ll I, char c){
  if(L == R && R == I){
    st[pos] = pres(c);
    return;
  }

  ll next = pos << 1, mid = (L+R) >> 1;

  if(L <= I && I <= mid){
    att(next, L, mid, I, c);
  }
  else{
    att(next+1, mid+1, R, I, c);
  }

  st[pos] = junta(st[next], st[next+1]);
}


pres query(ll pos, ll L, ll R, ll i, ll j){
  pres total;
  for(int i = 0; i < 26; i++) total.vet[i] = 0;
  if(R < i || L > j) return total;
  if( i <= L && R <= j){
    return st[pos];
  }

  ll next = pos << 1, mid = (L+R) >> 1;

  pres esq = query(next, L, mid, i, j);
  pres dir = query(next+1, mid+1, R, i, j);

  return junta(esq, dir);
}

int main(){
  iosbase;
  tie;

  cin >> s;
  build(1, 0, s.size()-1);

  int q, op, pos, i, j;
  pres ans;
  char c;
  cin >> q;
  while(q--){
    cin >> op;
    if(op == 1){
      cin >> pos >> c;
      att(1, 0, s.size()-1, pos-1, c);
    }
    else{
      cin >> i >> j;
      ans = query(1, 0, s.size()-1, i-1, j-1);
      cout << ans.cont() << endl;
    }
  }
}
