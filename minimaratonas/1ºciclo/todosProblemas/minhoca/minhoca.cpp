#include <bits/stdc++.h>

using namespace std;

#define N 1010

int n, m, mat[N][N];

int main(){
	
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) scanf("%d", &mat[i][j]);
	
	for(int i=0; i<n; i++){
		if(i%2 == 0)
			for(int j=0; j<m; j++) printf("%d ", mat[i][j]);
		else
			for(int j=m-1; j>=0; j--) printf("%d ", mat[i][j]);
	}
	printf("\n");
	
	
}
