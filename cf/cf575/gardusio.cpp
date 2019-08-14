
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

//~ </template>

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
  private:
    int q;
    int b, w;
    set< pair< int, int > > used;

    bool solve(const int &sourceX, const int &sourceY) {
      used.clear();
      queue< pair< int, int > > q;
      int black = b;
      int white = w;
      if ((sourceX + sourceY) & 1) {
        black -= 1;
      } else {
        white -= 1;
      }
      used.insert({sourceX, sourceY});
      q.push({sourceX, sourceY});
      while (q.empty() == false) {
        const int &i = q.front().first;
        const int &j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k += 1) {
          const int &x = i + dx[k];
          const int &y = j + dy[k];
          if (used.count({x, y}) == 1) {
            continue;
          }
          if ((x + y) & 1) {
            if (black == 0) {
              continue;
            }
            black -= 1;
          } else {
            if (white == 0) {
              continue;
            }
            white -= 1;
          }
          used.insert({x, y});
          q.push({x, y});
        }
      }
      return (black + white) == 0;
    }

  public:
    Solution() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    }

    void main() {
      cin >> q;
      while (q-- > 0) {
        cin >> b >> w;
        if (solve(100000000, 100000000) == true || solve(100000000, 100000000 + 1) == true) {
          cout << "YES" << endl;
          for (const auto &i: used) {
            cout << i.first << ' ' << i.second << endl;
          }
        } else {
          cout << "NO" << endl;
        }
      }
    }
};

int main() {
  Solution().main();
  return 0;
}
