#include <bits/stdc++.h>
using namespace std;

const int N = 99998;

int main(){
	srand(time(NULL));
	string vogal = "aeiou";
	int n = 3+rand()%N;
	cout << n << endl;
	for (int i=0; i<n; i++){
		int now = rand()%5;
		cout << vogal[now];
	}
	cout << endl;
	
}
