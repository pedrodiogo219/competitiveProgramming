#include <bits/stdc++.h>

using namespace std;

#define N 1010101

int acc[N];

int main(){
	
	int n, q, x;
	
	scanf("%d %d %d", &n, &q, &x);
	int a, b;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a);
		acc[i] = acc[i-1] + ( (a%x) == 0 );
	}
	
	while(q--){
		scanf("%d %d", &a, &b);
		printf("%d\n", acc[b] - acc[a-1]);
	}
	
	
}
