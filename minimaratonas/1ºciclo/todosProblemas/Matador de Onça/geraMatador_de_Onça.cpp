#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int X = 100000;

int main(){
	srand(time(NULL));
	int n = 1+rand()%N;
	cout << n << endl;
	for (int i=0; i<n; i++){
		int x = 1+rand()%X;
		if(i) cout << ' ';
		cout << x;
	}
	cout << endl;
}
