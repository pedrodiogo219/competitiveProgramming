#include <bits/stdc++.h>

using namespace std;

int main() {
	int robos, projetos;
	cin >> projetos >> robos;
	if(robos % projetos == 0)
		cout << "Robos de prontidao!\n";
	else
		cout << "Precisa de mais robos!\n";

	return 0;
}