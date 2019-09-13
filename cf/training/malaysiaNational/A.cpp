#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char mat[1010][1010], aux[1010][1010];
map < pair < char, char >, char > change;

void rotate(char c, const int &n){
  if(c == 'R'){
    int a = 0;
      for (int j=0; j<n; j++){
        int b =0;
        for (int i=n-1; i>=0; i--){
          aux[a][b] = change[{c,mat[i][j]}];
          b++;
        }
        a++;
      }
    }
    else {
      int a = 0;
      for (int j=n-1; j>=0; j--){
        int b = 0;
        for (int i=0; i<n; i++){
          aux[a][b] = change[{c, mat[i][j]}];
          b++;
        }
        a++;
      }
    }
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++) mat[i][j] = aux[i][j];
    }
}

int main(){
  int n;
  char str[110];
  scanf("%d %s", &n, &str);
  change[{'L','>'}] = '^';
  change[{'L','<'}] = 'v';
  change[{'L','^'}] = '<';
  change[{'L','v'}] = '>';
  change[{'R','>'}] = 'v';
  change[{'R','<'}] = '^';
  change[{'R','^'}] = '>';
  change[{'R','v'}] = '<';
  change[{'L','.'}] = '.';
  change[{'R','.'}] = '.';
  int L = 0, R = 0;
  for (int i=0; i<strlen(str); i++){
    char c = str[i];
    if(c == 'L') L++;
    else R++;
  }
  L %= 4;
  R %= 4;
  for (int i=0; i<n; i++) scanf("%s", mat[i]);
  for (int i=0; i<L; i++) rotate('L', n);
  for (int i=0; i<R; i++) rotate('R', n);
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      printf("%c", mat[i][j]);
    }
    puts("");
  }
}
