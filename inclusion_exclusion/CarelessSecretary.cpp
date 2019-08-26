#include<bits/stdc++.h>
using namespace std;

class CarelessSecretary{
public:
  const long long mod = 1000000007;

  long long fat[1010];
  long long mult(long long a, long long b){
    return (a%mod * b%mod)%mod;
  }
  long long add(long long a, long long b){
    return (a%mod + b%mod)%mod;
  }
  long long sub(long long a, long long b){
    return (a%mod - b%mod + mod) % mod;
  }

  long long fast_expo(long long base, long long e){
    if(e == 0) return 1LL;
    if(e == 1) return base;

    long long res = fast_expo(mult(base, base), e/2LL);
    if(e&1) res = mult(res, base);
    return res;
  }

  long long ddiv(long long a, long long b){
    return (a%mod * fast_expo(b, mod-2LL))%mod;
  }

  long long comb(long long c, long long k){
    return ddiv(fat[c], mult(fat[k], fat[c-k]));
  }

  void prepros(){
    fat[0] = 1LL;
    for(int i = 1; i <= 1005; i++){
      fat[i] = mult(fat[i-1], (long long)i);
    }
  }

  int howMany(int N, int K){
    prepros();
    long long ans = fat[N];
    long long falhos = 0LL;
    for(int i = 1; i <= K; i++){
      long long parcela = mult(comb(K, i), fat[N-i]);
      // cerr << "parcela: " << parcela << endl;
      if(i & 1){
        falhos = add(falhos, parcela);
      }else{
        falhos = sub(falhos, parcela);
      }
    }
    int sol = sub(ans, falhos);
    return sol;
  }
};

int main(){
  CarelessSecretary Sol;
  int a, b;
  cin >> a >> b;
  cout << Sol.howMany(a, b) << endl;
}
