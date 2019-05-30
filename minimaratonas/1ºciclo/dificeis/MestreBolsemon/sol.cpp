#include<bits/stdc++.h>
using namespace std;


int pokes[1000100];
int desaf[1000100];

int main(){

	int n; scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &desaf[i]);
	}
	
	int m; scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d", &pokes[i]);
	}
	
	sort(desaf, desaf+n);
	sort(pokes, pokes+m);



	int i=0, j=0;
	long long soma = 0;
	while(true){
		if(i>=m) break;
		if(j>=n) break;
		
		if( pokes[i] >= desaf[j] ){
			soma+=pokes[i];
			j++;
		}
		
		i++;
	}
	
	if(j>=n){
		printf("%d\n", soma);
	}else{
		printf("impossivel\n");
	}
}
