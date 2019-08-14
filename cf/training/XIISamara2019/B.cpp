#include <bits/stdc++.h>
using namespace std;

int main(){
  int cima = 0, baixo = 0, dois = 0;
  string a, b;
  cin >> a >> b;
  for (int i=0; i<a.size(); i++){
    if(a[i] == '#' && b[i] == '#') dois++;
    else if(a[i] == '#') cima++;
    else if(b[i] == '#') baixo++;
  }
  if(dois == 0 && cima != 0 && baixo != 0) {
    puts("NO");
    return 0;
  }
  string ans1, ans2;
  for (int i=0; i<a.size(); i++){
    if(cima > 0) ans1.push_back('#'), ans2.push_back('.'), cima--;
    else if(dois > 0) ans1.push_back('#'), ans2.push_back('#'), dois--;
    else if(baixo > 0) ans1.push_back('.'), ans2.push_back('#'), baixo--;
    else ans1.push_back('.'), ans2.push_back('.');
  }
  puts("YES");
  cout << ans1 << endl << ans2 << endl;
}
