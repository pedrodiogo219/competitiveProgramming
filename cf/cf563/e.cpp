#include<bits/stdc++.h>
using namespace std;

int main(){

  for(int n = 2; n <= 20; n++){
  std::vector<int> v;
  for(int i=1;i<=n;i++){
    v.push_back(i);
  }

  std::vector<int> consegui;
  int maior = 0;
  do{
    set<int> s;
    int ac = v[0];
    for(int i=0;i<n;i++){
      ac = __gcd(ac, v[i]);
      s.insert(ac);
    }
    maior = max(maior, (int) s.size());
    consegui.push_back((int)s.size());
  }while ( next_permutation(v.begin(), v.end()) );

  int cont = 0;
  for(int i = 0; i < (int)consegui.size(); i++){
    if(consegui[i] == maior) cont ++;
  }

  cout << "n: " << n << " cont: " << cont << endl;
  }
}
