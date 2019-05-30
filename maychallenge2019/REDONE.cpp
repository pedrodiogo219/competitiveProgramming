#include<bits/stdc++.h>
using namespace std;


#define mod % 1000000007

long v[1000100];



void processa(){
	v[0] = 0;
 	long last = 0;
	for(int i=1;i<1000050;i++){
		last = 
		(
			(
				(
					(last mod) + 	(i mod)
				)mod
			)
			+ 
			(
				(
					(last mod) * (i mod)
				) mod
			)
		)mod ;
		v[i] = last;
	}
}

int main(){
	processa();

	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		cout << v[x] << endl;
	}
}
