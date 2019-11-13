#include<bits/stdc++.h>
using namespace std;

int monstros[200100];
int MAX[200100];
pair<int, int> guerreiros[200100];
int n, m;

int bb(int x){
  int lo = 0, hi = m-1, mid;
  int ans = -1;
  while(lo <= hi){
    mid = (lo+hi)/2;

    if( guerreiros[mid].first >= x){
      ans = mid;
      hi = mid-1;
    }else{
      lo = mid+1;
    }

  }
  return ans;
}

int main(){
  int t; scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &monstros[i]);

    }

    scanf("%d", &m);
    int a, b;
    for(int i = 0; i < m; i++){
      scanf("%d %d", &a, &b);
      guerreiros[i] = {a,b};
      MAX[i] = 0;
    }

    sort(guerreiros, guerreiros+m);

    MAX[m-1] = guerreiros[m-1].second;
    for(int i = m-2; i>=0; i--){
      MAX[i] = max(MAX[i+1], guerreiros[i].second);
    }

    int pos = 0;
    int monstroAtual = 0;
    int quant = 0, dias = 0;
    bool flag = false;
    while(pos < n){
      monstroAtual = max(monstroAtual, monstros[pos]);
      quant+=1;

      int lim = bb(monstroAtual);
      if(lim == -1){
        flag = true;
        break;
      }
      if(MAX[lim] < quant){
        dias++;
        monstroAtual = monstros[pos];
        lim = bb(monstroAtual);
        if(lim == -1){
          flag = true;
          break;
        }
        quant = 1;
      }
      pos++;
    }


    if(flag){
      printf("-1\n");
    }
    else printf("%d\n", dias+1);
  }

}
