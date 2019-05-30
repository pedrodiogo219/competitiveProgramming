#include<bits/stdc++.h>
using namespace std;


int v[1000010];
int main(){
	int n; scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &v[i+1]);
	}
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	int menor = v[a];
	int maior = v[b];
	for(int i=a;i<=b;i++){
		menor = min(menor, v[i]);
		maior = max(maior, v[i]);
	}
	
	printf("%d\n", maior-menor);
}
