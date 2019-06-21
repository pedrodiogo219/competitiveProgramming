#include<bits/stdc++.h>
using namespace std;

pair<long long int, int> v[100100];

bool compare(pair< long long int,int> eu, pair<long long int, int> outro){
  if(outro.first == -1) return true;
  if(eu.first == -1) return false;
  return abs(eu.first) < abs(outro.first);
}

bool compare2(pair<long long int,int> eu, pair<long long int, int> outro){
  return eu.second < outro.second;
}

int main(){
  int n;
  long long aux;
  scanf("%d", &n);;
  for(int i = 0; i < n; i++){
    scanf("%lld", &aux);
    v[i] = make_pair(aux, i);
  }

  for(int i = 0 ; i < n;i++){
    if(abs(v[i].first) < abs(-v[i].first-1LL)){
      v[i].first = -v[i].first-1LL;
    }
  }

  sort(v, v+n, compare);
  //
  // for(int i = 0; i < n; i++){
  //   cout << " " << v[i].second;
  // }cout << endl;

  bool pos = true;
  for(int i = 0 ; i < n-1; i++){
    if(v[i].first < 0) pos = !pos;
  }

  // cout << "pos: " << pos << endl;
  //if(pos * v[n-1].first < 0LL)
  if(( !pos && v[n-1].first > 0) || (pos && v[n-1].first < 0)){
    v[n-1].first = -v[n-1].first-1;
  }

  sort(v, v+n, compare2);

  for(int i = 0; i < n; i++){
    if (i) printf(" ");
    printf("%lld", v[i].first);
  }
  printf("\n");

}
