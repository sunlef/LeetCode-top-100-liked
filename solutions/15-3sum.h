// https://leetcode.cn/problems/3sum
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    std::ranges::sort(nums);

    std::vector<std::vector<int>> returnV;

    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1, k = n - 1; j < k; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        while (k - 1 > j && nums[j] + nums[k] > -nums[i]) {
          k--;
        }
        if (nums[i] + nums[j] + nums[k] == 0) {
          returnV.push_back({nums[i], nums[j], nums[k]});
        }
      }
    }

    return returnV;
  }
};