// https://leetcode.cn/problems/merge-intervals
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    std::vector<std::vector<int>> returnV;
    std::ranges::sort(intervals);

    for (auto const &xi : intervals) {
      int li = xi[0];
      int ri = xi[1];

      if (returnV.empty() || li > returnV.back()[1] || ri < returnV.back()[0]) {
        returnV.push_back({li, ri});
      } else {
        returnV.back()[0] = std::min(returnV.back()[0], li);
        returnV.back()[1] = std::max(returnV.back()[1], ri);
      }
    }

    return returnV;
  }
};