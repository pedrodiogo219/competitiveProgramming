#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

#define pi acos(-1)

long double converte(long double N){
  return (N*pi) / 180.0;
}

int n, m;
int main(){
  // debug(co);
  iosbase;
  tie;

  int a, b, x;
  cin >> a >> b >> x;
  long double porcentagem = (long double) x / ((long double)a*a*b);
  // debug(porcentagem);
  long double angle, lo = 0.0, hi = 90.0;
  long double ans = 0.0;
  int it = 0;
  while( it < 100000 ){

    it++;
    angle = (lo+hi)/2.0;
    // debug(angle);
    long double t = tan(converte(90.0 - angle));
    long double co = t * b;
    // debug(co);
    if( co > a ){
      // cout << "triangulo de cima" << endl;
      t = tan(converte(angle));
      co = t * a;
      long double area =  (co * a)/2.0;
      // debug(area);
      // debug(area / (long double)(a*b));
      if(area / (long double)(a*b) <= (1.0 - porcentagem)){
        // cout << "resposta possivel" << endl;
        ans = angle;
        lo = angle + 0.0000000001;
      }else{
        hi = angle - 0.0000000001;
      }

    }else{
      // cout << "triangulo debaixo" << endl;
      long double area = (co * b) / 2.0;
      // debug(area);
      // debug( area / (long double)(a*b) );
      if( area / (long double)(a*b)>= porcentagem){
        ans = angle;
        // cout << "resposta possivel" << endl;
        lo = angle + 0.0000000001;
      }else{
        hi = angle - 0.0000000001;
      }
    }
  }

  cout << setprecision(10) << fixed << ans << endl;
}
