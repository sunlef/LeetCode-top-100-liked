/**
 * @brief
 * https://leetcode.cn/problems/two-sum
 *
 */
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::map<int, int> p;

    for (int i = 0; i < int(nums.size()); i++) {
      p[nums[i]] = i;
    }

    for (int i = 0; i < int(nums.size()); i++) {
      auto it = p.find(target - nums[i]);
      if (it != p.end() && it->second != i) {
        return {i, it->second};
      }
    }

    return {-1, -1};
  }
};