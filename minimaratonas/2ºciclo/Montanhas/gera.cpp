#include<bits/stdc++.h>
using namespace std;

vector<int> v, w, z;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  srand(time(NULL));

  int n = rand()%5 + 1;
  n*=2;

  cout << n << endl;


  if(rand()%3 == 0){
    for(int i = 0; i < n ; i++) z.push_back(i);
    random_shuffle(z.begin(), z.end());
    for(int i = 0; i < n; i++){
      if( i + i < n)
        v.push_back(z[i]);
      else
        w.push_back(z[i]);
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end(), greater<int>());

  }else{
    for(int i = 0; i < n; i++){
      if( i + i < n)
        v.push_back(rand()%10);
      else
        w.push_back(rand()%10);
    }
  }

  for(int i = 0; i < v.size(); i++){
    if(i) cout << " ";
    cout << v[i];
  }
  for(int i = 0; i < w.size(); i++){
    cout << " " << w[i];
  }
  cout << endl;

}
