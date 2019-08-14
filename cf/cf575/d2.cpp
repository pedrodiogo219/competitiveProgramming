#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, k;
string s;
string pattern1 = "RGB";
string pattern2 = "GBR";
string pattern3 = "BRG";

int acc1[201000];
int acc2[201000];
int acc3[201000];

void cost(int L, int R){
  int cont1 = 0;
  int cont2 = 0;
  int cont3 = 0;

  for(int i = 0; i+L <= R ; i++){
    if( s[i+L] != pattern1[ (i%3) ] ) cont1++;
    if( s[i+L] != pattern2[ (i%3) ] ) cont2++;
    if( s[i+L] != pattern3[ (i%3) ] ) cont3++;

    acc1[i] = cont1;
    acc2[i] = cont2;
    acc3[i] = cont3;

  }

}

int consulta(int L, int R){
  if(L == 0){
    return min(acc1[R], min(acc2[R], acc3[R]));
  }
  int a = acc1[R] - acc1[L - 1];
  int b = acc2[R] - acc2[L - 1];
  int c = acc3[R] - acc3[L - 1];

  return min(a, min(b, c));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int t; cin >> t;
  while(t--){
    cin >> n >> k;
    cin >> s;

    cost(0, n-1);

    int ans = INF;
    for(int i = 0; i+k-1 < n; i++){
      // cout << "intervalo: " << i << " " << i+k-1 << endl;
      ans = min(ans, consulta(i, i+k-1));
    }
    cout << ans << endl;

  }

}
