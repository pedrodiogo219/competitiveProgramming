//####### INCLUSION-EXCLUSION ########
// contar quantos números no intervalo [L, R] são
// divisíveis por pelo menos um dos números da lista

#include<bits/stdc++.h>
using namespace std;

class Divisibility{
public:

  long long int mmc(long long int a, long long int b){
    long long temp = __gcd(a, b);
    return (long long) ( a / temp * b);
  }

  int numDivisible(int L, int R, vector<int> a){

    vector<long long> p;
    for(const int ele : a){
      p.push_back((long long)ele);
    }

    long long int ans = 0LL;

    long long l = L;
    long long r = R;

    for(long long int mask = 1; mask < ( 1LL<<p.size() ); mask++){
      int bits = 0;
      long long num = 1LL;
      for(int i = 0; i < (int)p.size(); i++){
        if(mask & (1LL<<i)){
          bits++;
          num = mmc(num, p[i]);
        }
      }

      if(bits % 2 == 0){
        ans -= (r/num) - ((l-1LL)/num);
      }else{
        ans += (r/num) - ((l-1LL)/num);
      }
    }
    int sol = (int) ans;
    return sol;
  }
};

int bruta(int l, int r, vector<int> a){

  int sol = 0;
  for(int i = l; i<= r; i++){
    int cont = 0;
    for(int j = 0; j < (int)a.size(); j++){
      if(i % a[j] == 0){
        cont = true;
        break;
      }
    }
    if(cont) sol++;
  }

  return sol;
}

int main(){

  std::vector<int> a;
  a.push_back(2);
  a.push_back(3);
  a.push_back(6);

  Divisibility D;
  int erros = 0;
  for(int l = 1; l <= 10; l++){
    for(int r = l; r <= 1000; r++){
      int meu = D.numDivisible(l, r, a);
      int sol = bruta(l, r, a);
      cout << "l:" << l << "  r:" << r << endl;
      cout << meu << " --- " << sol;
      if(meu!=sol) {
        cout << " -ERROOOOOOOO";
        erros++;
      }
      cout << endl;
    }
  }

  cout << "erros: " << erros<< endl;
}
