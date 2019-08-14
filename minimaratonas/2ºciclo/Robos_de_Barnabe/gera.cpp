#include <bits/stdc++.h>

using namespace std;

int main() {
	srand (time(NULL));
	if ((rand() % 2) == 0)
		cout << rand() % 500 + 1 << " " << rand() % 500 + 1 << endl;
	else {
		int teste = rand() % 250 + 1;
		cout << teste << " ";
		cout << teste * (rand() % 10) << endl;
	}
	
	return 0;
}