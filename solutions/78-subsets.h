// https://leetcode.cn/problems/subsets
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();

    std::vector<std::vector<int>> returnV;
    for (int i = 0; i < (1 << n); i++) {
      std::vector<int> res;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          res.push_back(nums[j]);
        }
      }
      returnV.push_back(res);
    }

    return returnV;
  }
};