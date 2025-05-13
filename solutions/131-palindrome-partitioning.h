// https://leetcode.cn/problems/palindrome-partitioning
class Solution {
 public:
  vector<vector<string>> partition(string s) {
    std::vector<std::string> split;
    std::vector<std::vector<std::string>> returnV;

    split.push_back(std::string(1, s[0]));
    auto dfs = [&](auto &&self, int step) {
      if (step == int(s.size())) {
        for (auto const &si : split) {
          auto ti = si;
          std::ranges::reverse(ti);
          if (ti != si) {
            return;
          }
        }
        returnV.emplace_back(split);
        return;
      }

      while (!split.empty() && split.back().empty()) {
        split.pop_back();
      }
      split.push_back(std::string(1, s[step]));
      self(self, step + 1);
      split.back().pop_back();

      while (!split.empty() && split.back().empty()) {
        split.pop_back();
      }
      split.back() += s[step];
      self(self, step + 1);
      split.back().pop_back();
    };

    dfs(dfs, 1);
    return returnV;
  }
};