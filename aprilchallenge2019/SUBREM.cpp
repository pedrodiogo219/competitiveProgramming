#include<bits/stdc++.h>
using namespace std;


vector< vector<long long> > grafo;
long long n, x;
long long v[100010];



long long conta(long long u, long long pai){
	
	long long soma = v[u];
	
	for(int i=0; i < grafo[u].size(); i++){
		if(grafo[u][i]==pai) continue;
		soma+= conta(grafo[u][i], u);
	}	
	//cout << "eu to no vertice: " << u << endl;
	//cout << "soma: " << soma<< endl;
	return max(soma, -x);
}

int main(){
	long long a, b;
	int t; cin >> t;
	while(t--){
		cin >> n >> x;
		grafo.resize(n+5);
		for(int i=1;i<=n;i++) cin >> v[i];
		
		for(int i=0;i<n-1;i++){
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		
		long long soma = conta(1, -1);
		cout << soma << endl;

		
		grafo.clear();
	}
}
