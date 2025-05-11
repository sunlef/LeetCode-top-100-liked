// https://leetcode.cn/problems/longest-consecutive-sequence

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> exist;

    std::ranges::for_each(nums, [&exist](int xi) { exist.insert(xi); });

    int ans = 0;
    std::ranges::for_each(exist, [&exist, &ans](int xi) {
      if (exist.contains(xi - 1)) {
        return;
      }
      int yi = xi;
      while (exist.contains(yi)) {
        yi++;
      }
      ans = std::max(ans, yi - xi);
    });

    return ans;
  }
};