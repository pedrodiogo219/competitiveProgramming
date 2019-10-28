#include <bits/stdc++.h>
using namespace std;

const int N = 3003;

typedef long long ll;
int in[N];
vector < int > g[N];

struct pv{
  ll x, y;
  pv(){
    x = y = 0;
  }
  pv(ll _x, ll _y){
    x = _x, y = _y;
  }
};

pv toVet(pv a, pv b){
  return pv(b.x - a.x, b.y - a.y);
}

ll dot(pv a, pv b){
  return a.x*b.x + a.y*b.y;
}

ll cross(pv a, pv b){
  return a.x*b.y - a.y*b.x;
}

ll norm_sq(pv u){
  return dot(u, u);
}

struct enemy{
  ll x, y, a, r;
  bool see(enemy other){
    pv u = toVet(pv(x, y), pv(other.x, other.y));
    pv v = toVet(pv(x, y), pv(x+1, y));
    double angleRad = (acos(dot(u, v)/sqrt(norm_sq(u) * norm_sq(v))));
    ll angle = ceil((180.0*angleRad)/acos(-1.0));
    if(cross(v, u) < 0){
      angle *= -1;
    }
    //cout << "angle: " << angle << endl;
    if(a > 180){
      a = 180 - (a-180);
      a *= -1;
    }
    //cout << a << ' ' << angle << endl;
    ll um = a+r, dois = a-r;
    if(um > 180){
      um = 180 - (um - 180);
      um *= -1;
    }
    if(dois > 180){
      dois = 180-(dois-180);
      dois *= -1;
    }
    if(um <= -180){
      um = 180 - (um - 180);
      um *= -1;
    }
    if(dois <= -180){
      dois = 180-(dois-180);
      dois *= -1;
    }
    if((angle >= a && angle <= um) || (angle <= a && angle >= dois)) return true;
    return false;
  }
}vet[N];

int main(){
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++){
    long long x, y, a, r;
    scanf("%lld %lld %lld %lld", &vet[i].x, &vet[i].y, &vet[i].a, &vet[i].r);
  }
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if(i == j) continue ;
      //cout << i << ' ' << j << endl;
      if(vet[i].see(vet[j])){
        //cout << i << ' ' << j << endl;
        g[i].push_back(j);
        in[j]++;
      }
    }
  }
  bool flag = false;
  queue < int > fila;
  vector < int > ans;
  for (int i=1; i<=n; i++){
    if(in[i] == 0){
      fila.push(i);
      ans.push_back(i);
    }
  }
  while (!fila.empty()){
    int u = fila.front();
    fila.pop();
    for (int v : g[u]){
      in[v]--;
      if(in[v] == 0){
        fila.push(v);
        ans.push_back(v);
      }
    }
  }
  if(ans.size() != n) printf("-1\n");
  else {
    for (int i=0; i<ans.size(); i++){
      if(i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
}
