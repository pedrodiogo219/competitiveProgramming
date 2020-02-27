#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

tuple<int,int,int> t[100100];

unordered_map< int, unordered_map<int, queue<int> > > m;

int vis[100100];
int n;
int main(){
  scanf("%d", &n);
  int a, b, c;
  for(int i = 0; i < n-2; i++){
    scanf("%d %d %d", &a, &b, &c);
    t[i] = make_tuple(a, b, c);
    vis[a]++;
    vis[b]++;
    vis[c]++;

    m[a][b].push(c);
    m[a][c].push(b);
    m[b][a].push(c);
    m[b][c].push(a);
    m[c][a].push(b);
    m[c][b].push(a);
  }

  int atual = -1;
  for(int i = 0; i < n-2; i++){
    if(vis[ get<0>(t[i]) ] == 1 || vis[ get<1>(t[i]) ] == 1 || vis[ get<2>(t[i]) ] == 1){
      atual = i;
      break;
    }
  }

  while(true){
    a = get<0>(t[atual]);
    b = get<1>(t[atual]);
    c = get<2>(t[atual]);
    v = { a, b, c};

    debug(a);
    debug(b);
    debug(c);
    break;
  }



}
