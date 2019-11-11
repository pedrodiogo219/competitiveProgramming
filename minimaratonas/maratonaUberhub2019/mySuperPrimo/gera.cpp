#include<bits/stdc++.h>
using namespace std;

int ppow(int base, int pot){
  if(pot == 0) return 1;
  return base * ppow(base, pot-1);
}

int main(int argc, char * argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

  int ordem = atoi(argv[2]);
  int seed = atoi(argv[1]);
  srand(seed);

  int N = (rand() % ppow(10, ordem)) + 1;
  cout << N << endl;

  for(int i = 0; i < N; i ++){
    cout << (rand()%ppow(10, 2*ordem))+1 << endl;
  }


}
