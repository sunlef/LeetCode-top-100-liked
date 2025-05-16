// https://leetcode.cn/problems/majority-element
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int n = nums.size();
    auto it = nums.begin() + n / 2;
    std::nth_element(nums.begin(), it, nums.end());
    return *it;
  }
};