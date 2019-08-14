#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_rand(int val){
	ll a = (((1LL*rand())<<20LL)^rand())%val;
	return a;
}

int main(){
	srand(time(NULL));
	
	int n, q, x;
	n = get_rand(1000000)+1;
	q = get_rand(1000000)+1;
	x = get_rand(1000)+1;
	
	printf("%d %d %d\n", n, q, x);
	for(int i=0; i<n; i++) printf("%d%c", get_rand(1e3)+1, i==n-1?'\n':' ');
	while(q--){
		int a = get_rand(n)+1;
		int b = get_rand(n)+1;
		printf("%d %d\n", min(a, b), max(a, b));
	}
}
