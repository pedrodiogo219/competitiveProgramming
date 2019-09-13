#include<bits/stdc++.h>
using namespace std;

int vis[201][201][201];

struct tripla{
  int r, g, b;
  tripla(){
  }

  tripla(int x, int y, int z){
    r = x;
    g = y;
    b = z;
  }
};

int main(){

  int n; string s;
  cin >> n >> s;
  int rs = 0;
  int gs = 0;
  int bs = 0;

  for(char c : s){
    if(c == 'R') rs++;
    if(c == 'G') gs++;
    if(c == 'B') bs++;
  }

  queue<tripla> fila;
  fila.push(tripla(rs, gs, bs));
  vis[rs][gs][bs] = true;

  bool posR = false;
  bool posG = false;
  bool posB = false;

  while(!fila.empty()){
    tripla topo = fila.front();
    int r = topo.r;
    int g = topo.g;
    int b = topo.b;
    fila.pop();

    if(r == 1 && g == 0 && b == 0){
      posR = true;
      continue;
    }
    if(r == 0 && g == 1 && b == 0){
      posG = true;
      continue;
    }
    if(r == 0 && g == 0 && b == 1){
      posB = true;
      continue;
    }

    if(r >= 2){
      r--;
      if(!vis[r][g][b]) fila.push(tripla(r, g, b));
      vis[r][g][b] = true;
      r++;
    }
    if(g >= 2){
      g--;
      if(!vis[r][g][b]) fila.push(tripla(r, g, b));
      vis[r][g][b] = true;
      g++;
    }
    if(b >= 2){
      b--;
      if(!vis[r][g][b]) fila.push(tripla(r, g, b));
      vis[r][g][b] = true;
      b++;
    }

    if(r>=1 && g>=1){
      r--;
      g--;
      b++;
      if(!vis[r][g][b]) fila.push(tripla(r, g, b));
      vis[r][g][b] = true;
      r++;
      g++;
      b--;
    }
    if(r>=1 && b>=1){
      r--;
      g++;
      b--;
      if(!vis[r][g][b]) fila.push(tripla(r, g, b));
      vis[r][g][b] = true;
      r++;
      g--;
      b++;
    }
    if(b>=1 && g>=1){
      r++;
      g--;
      b--;
      if(!vis[r][g][b]) fila.push(tripla(r, g, b));
      vis[r][g][b] = true;
      r--;
      g++;
      b++;
    }
  }

  if(posB == true) cout << 'B';
  if(posG == true) cout << 'G';
  if(posR == true) cout << 'R';
  cout << endl;
}
