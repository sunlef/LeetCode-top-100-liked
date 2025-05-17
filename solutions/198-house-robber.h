// https://leetcode.cn/problems/house-robber
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    std::vector dp(n, std::vector<int>(2));
    dp[0][1] = nums[0];

    for (int i = 1; i < n; i++) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }

    return std::max(dp[n - 1][0], dp[n - 1][1]);
  }
};