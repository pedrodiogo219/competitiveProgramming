#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

const int N = 1010;
int vet[N], qtd[N];
long long fat[N];

long long fastExp(long long x, long long e) {
    if(e == 0LL) return 1LL;
    if(e == 1LL) return x%mod;
    long long val = fastExp(x, e/2LL)%mod;
    val = (val * val)%mod;
    if(e & 1LL) val = (val * x)%mod;
    return val;
}

int main() {
    int t;
    cin >> t;

    fat[0] = 1;
    for (long long i=1; i<1010; i++) {
        fat[i] = (fat[i-1]%mod * i%mod)%mod;
    }

    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        memset(qtd, 0, sizeof(qtd));
        for (int i=0; i<n; i++) {
            cin >> vet[i];
            qtd[vet[i]]++;
        }
        sort(vet, vet+n, greater<int>());
        int cnt = qtd[vet[k-1]];
        int want = 0;
        for (int i=0; i<k; i++){
            if(vet[i] == vet[k-1]) want++;
        }

        long long divisor = (fat[cnt-want]%mod * fat[want]%mod)%mod;
        long long ans = (fat[cnt]%mod * fastExp(divisor, mod-2)%mod)%mod;
        cout << ans << endl;
    }
}