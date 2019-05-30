#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]){
	
	
	unsigned rand_seed = atoi(argv[1]);
	srand((unsigned)rand_seed);
	
	
	int ordem = atoi(argv[2]);
	ordem = pow(10, ordem);

	
	int N = rand()%ordem+1;
	int M = rand()%ordem+1;
	
	printf("%d %d\n", N, M);	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(j != 0) printf(" %d", rand()%ordem + 1);
			else printf("%d", rand()%ordem + 1);
		}
		printf("\n");
	}

	
}
