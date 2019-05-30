#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii v[100010];
int m, n, k;

bool bs(int a, int b){
	
	ii x(a, b);

	int mid, esq = 0; int dir = k-1;
	while(esq<=dir){
		mid = (esq+dir) >> 1;
		
		if(v[mid] == x) return false;
		
		if(v[mid] < x) esq = mid+1;
		else dir = mid-1; 
	}
	
	return true;

}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> m >> n >> k;
		
		for(int i=0;i<k;i++){
			cin >> v[i].first >> v[i].second;
		}
	
		sort(v, v+k);
		
		long long int cont = 0;
		for(int i=0;i<k;i++){
			cont += bs(v[i].first+1, v[i].second);
			cont += bs(v[i].first-1, v[i].second);
			cont += bs(v[i].first, v[i].second+1);
			cont += bs(v[i].first, v[i].second-1);
		}
		
		cout << cont << endl;
	}
}
