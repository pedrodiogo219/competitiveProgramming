#include<bits/stdc++.h>
using namespace std;

int vn[20];

long long int memo[20][10][2][2];

long long int dp(int pos, int soma, bool difzero, bool menor){
  if(pos < 0) return difzero && soma == 0;

  if(memo[pos][soma][difzero][menor] != -1) return  memo[pos][soma][difzero][menor];

  long long int total = 0;

  if(menor){
    for(int i=0; i<10; i++){
      total += dp(pos-1, (soma+i)%10, (difzero || i!=0), menor);
    }
  }else{
    for(int i=0; i<vn[pos];i++){
      total+=dp(pos-1, (soma+i)%10, (difzero || i!=0), true);
    }
    total+=dp(pos-1, (soma+vn[pos])%10, (difzero || vn[pos]!=0), false);
  }

  return  memo[pos][soma][difzero][menor] = total;
}

int main(){
  int t; scanf("%d", &t);

  long long n = 0;

  while(t--){
    n++;
    //long long int n; scanf("%lld", &n);

    int i;
    long long int nn, res, ans = -1LL;
    long long int lo = 0, mid, hi = 1000000000000000000LL;
    while(lo <= hi){
      memset(memo, -1, sizeof(memo));
      mid = lo + ((hi - lo)/2);
      //printf("lo: %lld  --  mid: %lld  --  hi: %lld\n", lo, mid, hi);
      nn = mid; i = 0;

      int size = 0;
      while(nn){
        vn[i++] = nn % 10;
        nn/=10;
        size++;
      }
      // for(int k = 0; k < size; k++){
      //   cout << " " << vn[k];
      // }cout << endl;

      res = dp(size-1, 0, false, false);
      //printf("res: %lld\n", res);
      if(res >= n){
        ans = mid;
        hi = mid-1;
      }else{
        lo = mid+1;
      }
    }

    printf("%lld\n", ans);

  }


}
