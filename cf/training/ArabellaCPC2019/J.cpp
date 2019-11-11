#include <bits/stdc++.h>
using namespace std;
int n, ans=0;
string s;

int main()
{
    //ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.size();

    reverse(s.begin(), s.end());
    vector<int> vet;
    for(int i=0; i<n; i++) {
      vet.push_back(s[i]-'0');
    }
    vet.push_back(0);

    for(int i=0; i<n; i++) {
      if(vet[i] >= 6 || (vet[i] == 5 && (vet[i+1]>=6)) ) {
        ans+=(10-vet[i]);
        vet[i+1]++;
      }
      else {
        ans+=vet[i];
      }
    }
    ans+=vet[n];

    cout << ans << endl;
}
