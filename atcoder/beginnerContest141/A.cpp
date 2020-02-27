#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl;

#define iosbase ios_base::sync_with_stdio(false)
#define tie cin.tie();cout.tie();

#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

int n, m;
int main(){
  iosbase;
  tie;

  string s; cin >> s;

  if(s == "Sunny") cout << "Cloudy";
  if(s == "Cloudy") cout << "Rainy";
  if(s == "Rainy") cout << "Sunny";

  cout << endl;
}
