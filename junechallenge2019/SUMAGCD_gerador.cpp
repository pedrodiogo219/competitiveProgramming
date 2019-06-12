#include<bits/stdc++.h>
using namespace std;

int main(){

  srand(time(0));
  int t = 10;
  cout << t << endl;
  while(t--){

    int n = rand()%10+2;
    cout << n << endl;
    for(int i = 0 ; i < n ; i ++){
      if( i) cout << " ";
      cout << rand()%100 + 1;
    }
    cout << endl;



  }
}
