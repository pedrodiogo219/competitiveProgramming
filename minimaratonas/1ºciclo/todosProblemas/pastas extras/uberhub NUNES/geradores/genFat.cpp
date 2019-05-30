#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll count(ll n, ll p){
	ll answer=0;
	ll tmp = p;
	while(p<=n){
		answer+= n/p;
		//printf("p = %lld\n", p);
		p*=tmp;
	}
	return answer;
}

vector<int> prime;

void build(){
	bitset<10000001> bs;
	for(int i=2; ; i++){
		//printf("i = %d, size = %d\n", i, (int)prime.size());
		if(!bs[i]){
			prime.push_back(i);
			if(prime.size()>=5e5) break;
			for(int j=i; j<=1e7; j+=i) bs[j]=1;
		}
	}
}

int getRand(int n){
	return (((ll)rand()<<16)^(ll)rand())%n;
}


int main(){
	srand(time(NULL));
	build();
	//printf("prime[0] = %d\n", prime[0]);
	
	printf("%d %d\n", 83, 0);
	
	for(int i=0; i<90; i++){
		int p = prime[getRand(10)];
		ll q = count((ll(getRand(INT_MAX))<<10) ^ (ll)getRand(INT_MAX), p);
		printf("%d %lld\n", p, q);
	}
	
	for(int i=0; i<500; i++){
		int p = prime[getRand(prime.size())];
		ll q = count(getRand(INT_MAX), p);
		printf("%d %lld\n", p, q);
	}
	for(int i=0; i<400; i++){
		int p = prime[getRand(1000)];
		ll q = count(getRand(100000000), p);
		printf("%d %lld\n", p, q);
	}
	
	for(int i=0; i<9000; i++){
		int p = prime[getRand(prime.size())];
		ll q = count((ll(getRand(INT_MAX))<<10) ^ (ll)getRand(INT_MAX), p);
		printf("%d %lld\n", p, q);
	}
	
}
