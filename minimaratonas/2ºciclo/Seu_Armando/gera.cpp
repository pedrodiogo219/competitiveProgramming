#include <bits/stdc++.h>
using namespace std;

int main() {
	srand (time(NULL));
	int km = rand() % 500;
	int ha = rand() % 500;
	int horas = rand() % 500;
	int sf = rand() % 5;
	int salario = rand() % 500;
	cout << km << " " << ha << " " << horas << " " << sf << " " << salario << endl;

	return 0;
}