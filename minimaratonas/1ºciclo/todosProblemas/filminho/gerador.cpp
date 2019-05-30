#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]){
	
	
	unsigned rand_seed = atoi(argv[1]);
	srand((unsigned)rand_seed);
	
	
	int ordem = atoi(argv[2]);
	ordem = pow(10, ordem);

	
	int tamanho = rand()%ordem+1;	
	
	for(int i=0;i<tamanho;i++){
		printf("%c", 'A' + rand()%26);
	}
	printf("\n");
	
}
