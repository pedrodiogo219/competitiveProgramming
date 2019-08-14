#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_rand(int val){
	ll a = (((1LL*rand())<<20LL)^rand())%val;
	if(rand() % 2) a*= -1;
	return a;
}

int main(){
	srand(time(NULL));
	for(int i=0; i<3; i++)
		for(int j=0; j<2; j++){
			printf("%d", get_rand(abs(get_rand(INT_MAX))) );
			if(j) printf("\n");
			else printf(" ");
		}
}
