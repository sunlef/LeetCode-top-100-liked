// https://leetcode.cn/problems/maximum-subarray
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int minS = 0;
    int S = 0;

    int ans = 0;
    for (int x : nums) {
      S += x;
      minS = std::min(minS, S);
      ans = std::max(ans, S - minS);
    }

    auto it = std::ranges::max_element(nums);
    return *it > 0 ? ans : *it;
  }
};
