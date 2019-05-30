#include<bits/stdc++.h>
using namespace std;


bool ganho(long long int a, long long int b){
	if(a%b == 0) return true;
	
	if( ganho(b, a%b) ){
		if(a/b <= 1) return false;
	}
	
	return true;
}

int main(){
	int t; cin >> t;
	while(t--){
		long long int a, b;
		cin >> a >> b;
		if(b>a) swap(a,b);
		
		if(ganho(a, b)) cout << "Ari" << endl;
		else cout << "Rich" << endl;
		
	}
}
