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

  int janela = 0;
  debug(32 - __builtin_clz(janela) - (__builtin_popcount(janela) == 1));
}