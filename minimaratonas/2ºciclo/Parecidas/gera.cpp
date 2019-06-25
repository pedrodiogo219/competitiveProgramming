#include<bits/stdc++.h>
using namespace std;

int main(){

  srand(time(NULL));

  int n = rand()%100 + 1;
  cout << n << endl;

  int chanceDeDarCerto = rand()%3;

  if(chanceDeDarCerto != 0){
    for(int i = 0; i < n ;i++){
      char letra = rand()%26 + 'a' ;

      if( rand()%2 == 1){
        letra = letra + ('A' - 'a');
      }

      cout << letra;
    }
    cout << endl;

    for(int i = 0; i < n ;i++){
      char letra = rand()%26 + 'a' ;

      if( rand()%2 == 1){
        letra = letra + ('A' - 'a');
      }

      cout << letra;
    }
    cout << endl;
  }else{
    string a, b;
    a = "";
    b = "";

    for(int i = 0; i < n; i++){
      char letra1 = rand()%26 + 'a';
      char letra2 = rand()%26 + 'a';
      if(rand()%2 == 0){
        letra1 = letra1 + ('A'-'a');
        letra2 = letra2 + ('A'-'a');
      }

      a+=letra1;
      b+=letra2;
    }

    cout << a << endl;
    cout << b << endl;
  }


}
