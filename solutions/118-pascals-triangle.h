// https://leetcode.cn/problems/pascals-triangle
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans(numRows);

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          ans[i].push_back(1);
        } else {
          ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
        }
      }
    }
    return ans;
  }
};