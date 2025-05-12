// https://leetcode.cn/problems/longest-substring-without-repeating-characters
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    std::map<char, int> count;

    int ans = 0;
    for (int x = 0, y = -1; x < n; count[s[x]] -= 1, x++) {
      while (y + 1 < n && count[s[y + 1]] == 0) {
        y += 1;
        count[s[y]] += 1;
      }
      ans = std::max(ans, y - x + 1);
    }

    return ans;
  }
};