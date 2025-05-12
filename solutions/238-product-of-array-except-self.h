// https://leetcode.cn/problems/product-of-array-except-self
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      l[i] = i > 0 ? nums[i] * l[i - 1] : nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      r[i] = i < n - 1 ? nums[i] * r[i + 1] : nums[i];
    }

    std::vector<int> returnV(n);
    for (int i = 0; i < n; i++) {
      returnV[i] = (i > 0 ? l[i - 1] : 1) * (i < n - 1 ? r[i + 1] : 1);
    }
    return returnV;
  }
};