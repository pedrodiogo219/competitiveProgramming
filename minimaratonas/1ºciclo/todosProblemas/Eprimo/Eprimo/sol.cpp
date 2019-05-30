#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	
	ll n;
	
	cin >> n;
	
	int div = 0;
	for (ll i = 1; i <= n; ++i) {
		if (n % i == 0) {
			++div;
		}
	}
	if (div == 2) {
		cout << "primo\n";
	} else {
		cout << "nao primo\n";
	}
}
