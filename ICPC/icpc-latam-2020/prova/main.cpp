#include <bits/stdc++.h>

const int MAX_SIZE = 750 + 5;
const int MAX_SIZE_OTHER = 1e4 + 5;

const int MOD = 1'000'000'000 + 7;

int K, L, N;
int T[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE_OTHER][MAX_SIZE];
int P[MAX_SIZE_OTHER];

int solve(const int idx, const int last) {
  if (dp[idx][last] != -1) {
    return dp[idx][last];
  }
  if (idx == N) {
    return dp[idx][last] = 1;
  }
  int ans = 0;
  for (int i = 0; i < K; i += 1) {
    if (std::abs(T[last][i] - P[idx]) > L) {
      continue;
    }
    ans += solve(idx + 1, i);
    ans %= MOD;
  }
  return dp[idx][last] = ans;
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
  std::memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i < K; i += 1) {
    ans += solve(1, i);
    ans %= MOD;
  }
  std::cout << ans << std::endl;
}

int32_t main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  solve_test_case();
  return 0;
}