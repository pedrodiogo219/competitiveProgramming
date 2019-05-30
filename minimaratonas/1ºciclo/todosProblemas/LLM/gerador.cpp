#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]){
	
	
	unsigned rand_seed = atoi(argv[1]);
	srand((unsigned)rand_seed);
	
	
	int ordem = atoi(argv[2]);
	ordem = pow(10, ordem);

	
	int r1 = rand()%ordem;
	int r2 = rand()%ordem;
	
	
	printf("%d\n%d\n", r1, r2);
}
