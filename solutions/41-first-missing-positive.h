// https://leetcode.cn/problems/first-missing-positive

#include <ranges>

class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i : std::views::iota(0, n) | std::views::filter([&](int x) {
                   return nums[x] < 1 || nums[x] > n;
                 })) {
      nums[i] = n + 1;
    }

    auto isTagged = [&](int i) { return nums[i] < 0; };

    for (int i = 0; i < n; i++) {
      const int &num = std::abs(nums[i]);
      if (num > 0 && num <= n) {
        int &tag = nums[num - 1];
        tag = -std::abs(tag);
      }
    }

    for (int i = 0; i < n; i++) {
      if (!isTagged(i)) {
        return i + 1;
      }
    }

    return n + 1;
  }
};