#include<bits/stdc++.h>
using namespace std;


int bit[100100], vet[100100];
int n;

int soma(int pos){
	int s = 0;
	while(pos > 0){
		s+=bit[pos];
		pos-=(pos & -pos);
	}
	return s;
}

void atualiza(int pos){
	while(pos<=n){
		bit[pos]++;
		pos+=(pos & -pos);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n, n!=0){
	memset(bit, 0, sizeof bit);
	for(int i=1;i <=n ;i++){
		cin >> vet[i];
	}
	
	int cont = 0;
	for(int i=n; i>=1; i--){
		cont += soma(vet[i]-1);
		atualiza(vet[i]);
	}

	if(cont%2==0) cout << "Carlos" << endl;
	else cout << "Marcelo" << endl;
	
	//cout << "cont: " << cont << endl;
	}
}
