#include<bits/stdc++.h>
using namespace std;

#define inf 20000000000000000

long long xs[10010];
long long ys[10010]; 

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		
		
		long long int x, y;
		for(int i=0;i<n;i++){
			scanf("%lld %lld", &x, &y);
			
			xs[i] = (x-y);
			ys[i] = (x+y);
		}
		
		sort(xs, xs+n);
		sort(ys, ys+n);
		
		long long int dist = inf;
		for(int i=1;i<n;i++){
			dist = min(dist, xs[i]-xs[i-1]);
		}
		for(int i=1;i<n;i++){
			dist = min(dist, ys[i]-ys[i-1]);
		}
		
		double result = (double)(dist / (double)2.0 );
		printf("%.7lf\n", result);
	}
}
