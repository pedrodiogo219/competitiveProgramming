#include <bits/stdc++.h>
using namespace std;

int v[15][15], t, a, b;
char s[1005];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
bool flag;
char m[] = {'U', 'L', 'R', 'D'};

bool valid(int x, int y) {
  return  !(x == 0 || y == 0 || x > 12 || y > 12 || v[x][y] == 2);
}

void dfs(int x, int y, int k) {
    if(flag) return;

    if(v[x][y] == 1) {
      printf("%d\n", k);
      printf("%s\n", s);
      flag = 1;
      return;
    }

    for(int i=0; i<4; i++) {
      int xx = x+dr[i];
      int yy = y+dc[i];

      if(!valid(xx, yy)) continue;

      s[k] = m[i]; s[k+1] = '\0';
      int aux = v[x][y];
      v[x][y] = 2;
      dfs(xx,yy,k+1);
      v[x][y] = aux;
    }
}
int main()
{

  v[3][3] = 1;
  v[3][10] = 1;
  v[10][3] = 1;
  v[10][10] = 1;

  v[6][6] = v[6][7] = 2;
  v[7][6] = v[7][7] = 2;

  v[10][2] = 2;
  v[10][11] = 2;

  v[9][2] = v[9][3] = 2;
  v[9][10] = v[9][11] = 2;

  cin >> t;

  while(t--) {
    flag = 0;
    cin >> a >> b;

    s[0] = '\0';
    dfs(a,b,0);
  }

}
