// https://leetcode.cn/problems/word-break
class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    std::vector<int> visited(n + 1);
    visited[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (auto const &t : wordDict) {
        if (i >= int(t.size()) && visited[i - int(t.size())] &&
            s.substr(i - int(t.size()), t.size()) == t) {
          visited[i] = 1;
        }
      }
    }

    return visited[n];
  }
};