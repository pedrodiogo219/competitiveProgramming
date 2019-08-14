#include <bits/stdc++.h>

using namespace std;

int main() {
	int r, km, ha, horas, sf, salario;
	cin >> km >> ha >> horas >> sf >> salario;
	r = ((km+ha+horas)*sf)-salario;
	cout << "Nao creio, Seu Armando! " << r << endl;

	return 0;
}