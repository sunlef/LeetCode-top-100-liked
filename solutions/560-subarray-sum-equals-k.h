// https://leetcode.cn/problems/subarray-sum-equals-k
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    std::map<int, int> count;
    count[0] = 1;

    int sum = 0, ans = 0;

    for (int x : nums) {
      sum += x;
      ans += count[sum - k];
      count[sum] += 1;
    }

    return ans;
  }
};