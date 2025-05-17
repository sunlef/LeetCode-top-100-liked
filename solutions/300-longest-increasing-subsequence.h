// https://leetcode.cn/problems/longest-increasing-subsequence
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    std::vector<int> dp;
    for (int x : nums) {
      auto it = std::lower_bound(dp.begin(), dp.end(), x);
      if (it == dp.end()) {
        dp.push_back(x);
      } else {
        *it = x;
      }
    }

    return dp.size();
  }
};