#include<bits/stdc++.h>
using namespace std;

long long int vet[20];
int main(){
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%lld", &vet[i]);
	}

	long long int ans = n;
	for(long long mask = 1; mask < (1 << m); mask++){
		long long int mmc = 1, cont = 0;
		for(int i = 0; (1 << i) <= mask; i++){
			if(mask & (1 << i)){
				mmc = (mmc)/__gcd(mmc, vet[i]) * vet[i];
				cont++;
			}
		}
		if(cont & 1){
			ans -= n/mmc;
		}else{
			ans += n/mmc;

		}
	}
	printf("%lld\n", ans);


}
