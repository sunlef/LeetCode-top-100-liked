// https://leetcode.cn/problems/sliding-window-maximum
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::deque<int> q;

    std::vector<int> returnV;
    for (int i = 0; i < int(nums.size()); i++) {
      while (!q.empty() && nums[q.back()] < nums[i]) {
        q.pop_back();
      }
      q.push_back(i);

      while (q.front() < i - k + 1) {
        q.pop_front();
      }

      if (i >= k - 1) {
        returnV.push_back(nums[q.front()]);
      }
    }

    return returnV;
  }
};