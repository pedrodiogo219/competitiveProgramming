#include<bits/stdc++.h>
using namespace std;


struct ii{
    int first, second, idx;
    ii(){
      first = 0;
      second = 0;
      idx = -1;
    }
};

bool cmp(ii a, ii b){
  if(a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}


ii vet[300100];

int main(){

  int n; scanf("%d", &n);
  int a, b;
  for(int i = 0; i < n; i++){
    scanf("%d %d", &a, &b);
    vet[i].first = a;
    vet[i].second = b;
    vet[i].idx = i+1;
  }

  sort(vet, vet+n, cmp);

  int ans = 0;
  int A = 1, B = 2;
  int mid, lo = 0, hi = n-1;
  for(int i = n-1; i >= 0; i--){
    vet[i].first;

    lo = 0;
    hi = i-1;

    int atual = 0;
    while(lo <= hi){
      mid = (lo+hi)/2;

      if(vet[mid].first < vet[i].second){
        lo = mid+1;
      }
      else if(vet[mid].second > vet[i].first){
        hi = mid-1;
      }
      else{
        atual = vet[mid].first + vet[i].first;
        a = vet[mid].idx;
        b = vet[i].idx;
        lo = mid+1;
      }
    }

    if(atual > ans){
      ans = atual;
      A = a;
      B = b;
    }
  }

  if(ans == 0){
    for(int i = 0; i < n-1; i++){
      if(vet[i].second <= vet[n-1].first){
        ans = vet[i].first;
        A = vet[i].idx;
        B = vet[n-1].idx;
      }
    }
  }
  printf("%d\n", ans);
  printf("%d %d\n", A, B);
}
