#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s[3];
  int a, b;
  cin >> s[0];
  cin >> s[1];
  cin >> s[2];

  for(int i=0; i<3; i++) {
    for(int j=0; j<10; j++) {
      if(s[i][j] == '=') {
        a = i;
        b = j;
        i = j = 10;
      }
    }
  }

  b++;
  for(int i=b; i<10; i++) {
    if(s[a][i] != '.') {
      printf("%c\n", s[a][i]);
      return 0;
    }
  }
  puts("You shall pass!!!");

}
