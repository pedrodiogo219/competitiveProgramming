#include <bits/stdc++.h>
using namespace std;

const int N = 55;

struct pv {
  int x, y;
  pv(){
    x = y = 0;
  }
  pv(int _x, int _y){
    x = _x, y = _y;
  }
  int operator * (pv aux) {
    return x * aux.y - y * aux.x;
  }
  bool operator < (pv aux) const {
    if(x != aux.x) return x < aux.x;
    return y < aux.y;
  }
}vet[N];

pv toVet(pv u, pv v){
    return pv(v.x - u.x, v.y - u.y);
}

int ori(int val){
	if(val > 0) return 1;
	else if (val < 0) return -1;
	return 0;
}

bool insideTriangle(vector < pv > tri, pv p){
  int a, b, c;
	a = ori(toVet(vet[0], vet[1]) * toVet(vet[0], p));
	b = ori(toVet(vet[1], vet[2]) * toVet(vet[1], p));
	c = ori(toVet(vet[2], vet[0]) * toVet(vet[2], p));
	return (a == b && a == c);
}

int main(){
  int t;
  int test = 0;
  scanf("%d", &t);
  while (t-- > 0){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++){
      scanf("%d %d", &vet[i].x, &vet[i].y);
    }
    sort(vet, vet+n);
    //for (int i=0; i<n; i++) cout << vet[i].x << ' ' << vet[i].y << endl;
    pv lower[55], upper[55];
    int szLower = 0;
    int szUpper = 0;
    for (int i=0; i<n; i++){
      while(szLower > 1 && toVet(lower[szLower-2], lower[szLower-1])*toVet(lower[szLower-2], vet[i]) < 0){
        szLower--;
      }
      lower[szLower++] = vet[i];
      while(szUpper > 1 && toVet(upper[szUpper-2], upper[szUpper-1])*toVet(upper[szUpper-2], vet[i]) > 0){
        szUpper--;
      }
      upper[szUpper++] = vet[i];
    }
    vector < pv > pol;
    for (int i=0; i<szLower-1; i++) pol.push_back(lower[i]);
    for (int i=szUpper-1; i>=0; i--) pol.push_back(upper[i]);
    printf("Case %d:\n", ++test);
    for (auto x : pol){
      printf("%d %d\n", x.x, x.y);
    }
    for (int i=0; i<m; i++){
      pv point;
      scanf("%d %d", &point.x, &point.y);
      vector < pv > aux;
      aux.push_back(pol[0]);
      bool flag = false;
      for (int i=1; i<pol.size()-2; i++){
        aux.push_back(pol[i]);
        aux.push_back(pol[i+1]);
        flag = insideTriangle(aux, point);
        aux.pop_back();
        aux.pop_back();
      }
      printf("%d %d ", point.x, point.y);
      puts((flag)? "is unsafe!" : "is safe!");
    }
  }
}
