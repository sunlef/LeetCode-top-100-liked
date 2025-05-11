// https://leetcode.cn/problems/move-zeroes
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    for (int x = 0, y = 0;;) {
      while (x < n && nums[x] != 0) {
        x++;
      }
      y = std::max(x, y);
      while (y < n && nums[y] == 0) {
        y++;
      }
      if (y < n) {
        std::swap(nums[x], nums[y]);
      } else {
        break;
      }
    }
  }
};