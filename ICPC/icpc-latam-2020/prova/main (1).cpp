#include <bits/stdc++.h>

#define int int64_t

const int MAX_SIZE = 750 + 5;
const int MAX_SIZE_OTHER = 1e4 + 5;

const int MOD = 1'000'000'000 + 7;

template <typename T>
class FenwickTree {
 public:
  explicit FenwickTree(const int size) : accum(size, this->DEFAULT_VALUE) {}

  void resize(const int size) {
    if (size < 0) {
      assert(false);
    }
    this->accum.resize(size);
  }

  void reset() { std::fill(accum.begin(), accum.end(), this->DEFAULT_VALUE); }

  void update(const int idx, const T value) {
    if (idx <= 0) {
      assert(false);
    }
    if (idx >= static_cast<int>(accum.size())) {
      assert(false);
    }
    for (int i = idx; i < static_cast<int>(accum.size()); i += i & (-i)) {
      this->accum[i] += value;
      this->accum[i] %= MOD;
    }
  }

  T query(const int idx) const {
    if (idx >= static_cast<int>(this->accum.size())) {
      assert(false);
    }
    T ans = 0;
    for (int i = idx; i > 0; i -= i & (-i)) {
      ans += this->accum[i];
      ans %= MOD;
    }
    return ans;
  }

 private:
  std::vector<T> accum;
  const T DEFAULT_VALUE = 0;
};

int K, L, N;
int T[MAX_SIZE][MAX_SIZE];
int P[MAX_SIZE_OTHER];

int find_l(const int current, const int idx) {
  int lo = 0;
  int hi = K - 1;
  int ans = -1;
  while (lo <= hi) {
    const int mid = lo + ((hi - lo) >> 1);
    if (T[current][mid] >= P[idx] - L) {
      hi = mid - 1;
      ans = mid;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

int find_r(const int current, const int idx) {
  int lo = 0;
  int hi = K - 1;
  int ans = -1;
  while (lo <= hi) {
    const int mid = lo + ((hi - lo) >> 1);
    if (T[current][mid] <= P[idx] + L) {
      lo = mid + 1;
      ans = mid;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}

void solve_test_case() {
  std::cin >> K >> L;
  for (int i = 0; i < K; i += 1) {
    for (int j = 0; j < K; j += 1) {
      std::cin >> T[i][j];
    }
  }
  std::cin >> N;
  for (int i = 1; i < N; i += 1) {
    std::cin >> P[i];
  }

  std::vector<FenwickTree<int64_t>*> dp(N + 10);
  for (auto& i : dp) {
    i = new FenwickTree<int64_t>(K + 10);
  }

  for (int i = 0; i < K; i += 1) {
    dp[N]->update(i + 1, 1);
  }

  for (int idx = N - 1; idx > 0; idx -= 1) {
    for (int current = 0; current < K; current += 1) {
      const int nxt_l = find_l(current, idx);
      const int nxt_r = find_r(current, idx);
      if (nxt_l == -1 or nxt_r == -1 or nxt_l > nxt_r) {
        continue;
      }
      assert(T[current][nxt_l] >= P[idx] - L);
      assert(T[current][nxt_r] <= P[idx] + L);
      const auto add =
          dp[idx + 1]->query(nxt_r + 1) - dp[idx + 1]->query(nxt_l);
      dp[idx]->update(current + 1, add);
    }
  }

  std::cout << dp[1]->query(K) << std::endl;
}

int32_t main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  solve_test_case();
  return 0;
}