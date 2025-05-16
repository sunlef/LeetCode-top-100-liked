// https://leetcode.cn/problems/permutations
class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();

    std::vector<std::vector<int>> returnV;

    std::vector<int> res;
    std::vector<int> visited(n);
    auto dfs = [&](auto &&self, int step) -> void {
      if (step == n) {
        returnV.push_back(res);
        return;
      }
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          visited[i] = 1;
          res.push_back(nums[i]);
          self(self, step + 1);
          visited[i] = 0;
          res.pop_back();
        }
      }
    };

    dfs(dfs, 0);
    return returnV;
  }
};