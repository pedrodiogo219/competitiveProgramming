//~ <template>

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

//~ </template>

class Solution {
private:
  string vowels = "aeiou";
  vector< string > possibilities;
  
  void generate(const string &s) {
    if (int(s.size()) == 3) {
      this->possibilities.push_back(s);
      return;
    }
    for (const char &c: this->vowels) {
      this->generate(s + string(1, c));
    }
  }

public:
  Solution() {
    this->generate("");
  }

  void main() {
    int n;
    string s;
    cin >> n >> s;
    int qtd = 0;
    string ans = "";
    for (const auto &goal: this->possibilities) {
      int current = 0;
      for (int i = 0; i < n - 2; i += 1) {
        bool valid = true;
        for (int j = 0; j < 3; j += 1) {
          valid &= (s[i + j] == goal[j]);
        }
        if (valid == true) {
          current += 1;
        }
      }
      if (current >= qtd) {
        qtd = current;
        ans = goal;
      }
    }
    cout << ans << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Solution().main();
  return 0;
}