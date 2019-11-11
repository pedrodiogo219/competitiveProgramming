#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  sort(str.begin(), str.end(), greater < char >());
  for (int i=0; i<26; i++){
    string ans;
    for (int i=0; i<str.size(); i++){
      if(i+1 < str.size() && str[i] == str[i+1] && str[i] != 'z'){
        ans.push_back(str[i]+1);
        i++;
      }
      else ans.push_back(str[i]);
    }
    str = ans;
  }
  cout << str << endl;
}
