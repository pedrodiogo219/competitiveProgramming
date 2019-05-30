#include<bits/stdc++.h>
using namespace std;

int v[100010];

int main(){
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> v[i];
	}

	int m = 0;
	for(int i=0;i<n;i++){
		if(v[i] > m) m = v[i];
	}

	int mm = 0;
	for(int i=0;i<n;i++){
		if( v[i] > mm && v[i] < m) mm = v[i];
	}

	cout << mm << endl;
}

