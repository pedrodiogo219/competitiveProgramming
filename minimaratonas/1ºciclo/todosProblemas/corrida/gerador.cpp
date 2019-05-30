#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]){
	
	
	unsigned rand_seed = atoi(argv[1]);
	srand((unsigned)rand_seed);
	
	
	int ordem = atoi(argv[2]);
	ordem = pow(10, ordem);

	
	int tamanho = rand()%ordem+1;
	printf("%d\n", tamanho);	
	
	int x;
	for(int i=0;i<tamanho;i++){
		x = (rand()%ordem) +1;
		if(i) printf(" %d", x);
		else  printf("%d", x);
	}
	printf("\n");
	
	int a, b;
	a = rand()%tamanho + 1;
	b = rand()%tamanho + 1;
	
	printf("%d %d\n", min(a, b), max(a,b));
	
}
