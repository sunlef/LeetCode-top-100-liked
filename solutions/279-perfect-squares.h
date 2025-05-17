// https://leetcode.cn/problems/perfect-squares
class Solution {
 public:
  int numSquares(int n) {
    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    for (int i = 1; i <= n; i++) {
      if (i * i <= n) {
        dp[i * i] = 1;
      }
      for (int j = 1; i + j * j <= n; j++) {
        dp[i + j * j] = std::min(dp[i + j * j], dp[i] + 1);
      }
    }
    return dp[n];
  }
};