#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]){
	
	
	unsigned rand_seed = atoi(argv[1]);
	srand((unsigned)rand_seed);
	
	
	int ordem = atoi(argv[2]);
	ordem = pow(10, ordem);

	
	int tamanhoN = rand()%ordem + 1;
	int tamanhoM = rand()%ordem + 1;
	
	if(tamanhoM < tamanhoN){
		int aux = tamanhoM;
		tamanhoM = tamanhoN;
		tamanhoN = aux;
	}
	
	printf("%d\n", tamanhoN);
		
	int x;
	for(int i=0;i<tamanhoN;i++){
		x = (rand()%ordem) +1;
		if(i) printf(" %d", x);
		else  printf("%d", x);
	}
	printf("\n");
	
	printf("%d\n", tamanhoM);
		
	for(int i=0;i<tamanhoM;i++){
		x = (rand()%ordem) +1;
		if(i) printf(" %d", x);
		else  printf("%d", x);
	}
	printf("\n");	
	
	
}
