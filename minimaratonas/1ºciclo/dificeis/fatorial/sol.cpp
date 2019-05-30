#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll count(ll n, ll p){
	ll answer=0;
	ll tmp = p;
	while(p<=n){
		answer+= n/p;
		p*=tmp;
	}
	return answer;
}

ll busca(ll p, ll q){
	
	ll ini=1, fim=1000000000000000000LL, mid, answer=-1;
	
	while(ini<=fim){
		mid = (ini+fim)>>1;
		if(count(mid, p) >= q){
			fim = mid-1;
			answer = mid;
		}else ini = mid+1;
	}
	return answer;
}

int main(){
	
	ll p, q;
	
	while(scanf("%lld %lld", &p, &q)!=EOF){
		printf("%lld\n", busca(p, q));
	}
	
}
