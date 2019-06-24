#include<bits/stdc++.h>
using namespace std;

double convert1(double n){
  double res = ((n*3.2));
  return res;
}

double convert2(double n){
  return (n - n*0.05);
}

double convert3(double n){
  return n/2.0;
}

int main(){

  double n, preco;
  cin >> n >> preco;

  double total = n;
  int cont = 0;
  while(total < preco){
    double a = convert1(total);
    double b = convert2(a);
    double c = convert3(b);
    total += c;
    cont++;

    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl;
    // cout << "c: " << c << endl;
    // cout << "T: " << total << endl << endl;
  }
  cout << cont << endl;
  cout << setprecision(2) << fixed << (double)total-(double)preco << endl;


}
