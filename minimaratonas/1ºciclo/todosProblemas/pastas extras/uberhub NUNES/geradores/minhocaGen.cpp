#include <bits/stdc++.h>

using namespace std;

#define N 1010

typedef long long ll;

int n, m, mat[N][N];

int getRand(ll n){
	return (((ll)rand()<<30)^ll(rand())) % n;
}	

int main(){
	int n, m;
	n=getRand(1000)+1;
	m=getRand(1000)+1;
	printf("%d %d\n", n, m);
	
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++)
			printf("%d%c", getRand(1000000), j==m-1 ? '\n' : ' ');
}
