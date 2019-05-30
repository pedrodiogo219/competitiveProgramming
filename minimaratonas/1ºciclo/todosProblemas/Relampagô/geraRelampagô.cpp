#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int X = 50;
const int resp = 3;
int vet[N];

int main()
{
	srand(time(NULL));
	int n = 1 + rand()%N/resp;
	cout << resp*n << endl;
	long long sum = 0LL;
	for (int i=0; i<n; i++){
		int x = 1 + rand()%(2*X)-X;
		vet[i] = x;
	}
	for (int i=0; i<resp*n; i++){
		if(i) cout << ' ';
		cout << vet[i%n];
	}
	cout << endl;
}
