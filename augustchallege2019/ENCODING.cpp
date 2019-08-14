#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

ll dezElevadoA[100100];
void preProcess(){
  dezElevadoA[0] = 1;
  for(int i = 1; i < 100010; i++){
    dezElevadoA[i] = (dezElevadoA[i-1] * 10LL) % MOD;
  }
}


int n, m;
string L, R;

pair<ll, ll> memo[100100][2][13];

void limpa_memo(){
  for(int i = 0; i < 100100; i++){
    for(int k = 0; k < 2; k++){
      for(int j = 0; j < 13; j++){
        memo[i][k][j] = {-1, -1};
      }
    }
  }
}

pair<ll, ll> dp(int pos, bool menorR, int last){
  if(pos == m) return {0, 1};
  if(memo[pos][menorR][last].first != -1 && memo[pos][menorR][last].second != -1) return memo[pos][menorR][last];

  ll res = 0;
  pair<ll,ll> prox;
  if(menorR){
    for(int i = 0; i <= 9; i++){
      prox = dp(pos+1, true, i);
      if(i != last) prox.first = (prox.first + ((i*dezElevadoA[m-pos-1])%MOD *prox.second)%MOD)%MOD;
      res = (res + prox.first)%MOD;
    }
    return memo[pos][menorR][last] = {res, (10*prox.second)%MOD };
  }

  else{
    ll prim = -1;
    for(int i = 0; i <= R[pos]-'0'; i++){
      if(i == R[pos]-'0') {
        prox = dp(pos+1, false, i);
      }
      else{
        prox = dp(pos+1, true, i);
      }

      if(prim == -1){
        prim = prox.second;
      }

      if( i!= last) prox.first = (prox.first + ((i*dezElevadoA[m-pos-1])%MOD *prox.second)%MOD)%MOD;
      res= (res + prox.first)%MOD;
    }
    return memo[pos][menorR][last] = {res, ((prox.second + ( (R[pos]-'0')*prim)%MOD)%MOD) };
  }

}


ll mult(ll a, ll b){
  return (a%MOD * b%MOD)%MOD;
}
ll soma(ll a, ll b){
  return (a%MOD + b%MOD)%MOD;
}

ll num[20];
ll f( ll x ){
  int n = 0;
  while(x > 0){
    num[n++] = x%10;
    x/=10;
  }

  num[n] = -1;

  ll sum = 0;
  for(int i = n-1; i >= 0; i--){
    if( num[i] == num[i+1] ) continue;
    sum = soma(sum , mult(num[i], dezElevadoA[i]));
  }

  return sum;
}

ll sol_bruta(ll L, ll R){
  ll sum = 0;
  for(ll i = L; i <= R; i++){
    sum= soma(sum, f(i));
  }
  return sum;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t, lixo; cin >> t;
  preProcess();
  while(t--){
    cin >> n >> L;
    cin >> m >> R;

    // ll A = stoi(L);
    // ll B = stoi(R);

    limpa_memo();
    pair<ll, ll> ans = dp(0, false, 11);

    R = L;
    m = n;
    limpa_memo();
    pair<ll, ll> outro = dp(0, false, 11);

    ll acc = 0, ult = '*';
    for(int i = 0; i < L.size(); i++){
      if(L[i] != ult) acc = (acc + ( (L[i]-'0') * dezElevadoA[n-i-1])%MOD)%MOD;
      ult = L[i];
    }

    // cout << "dp(" << B << ") = " << ans.first << endl;
    // cout << "dp(" << A << ") = " << outro.first << endl;
    // cout << "acc: " << acc << endl;

    ll sol = (((ans.first - outro.first)%MOD) + acc)%MOD;
    if(sol < 0) sol = MOD + sol;

    cout << sol << endl;
    // ll bruta = sol_bruta(A, B);
    // cout << "L: " << A << " R: " << B << endl;
    // cout << sol << " ---- ";
    // cout << bruta;
    // if(sol!=bruta) cout << "   ERRO";
    // cout << endl;




  }
}
