// https://leetcode.cn/problems/minimum-window-substring
class Solution {
 public:
  string minWindow(string s, string t) {
    std::map<char, int> tCount, sCount;
    for (char c : t) {
      tCount[c] += 1;
    }

    auto pred = [&]() {
      for (auto const &[ch, cnt] : tCount) {
        if (sCount[ch] < cnt) {
          return false;
        }
      }
      return true;
    };

    int n = s.size();
    std::string returnS{};
    for (int x = 0, y = -1; x < n; sCount[s[x]] -= 1, x++) {
      while (y + 1 < n && !pred()) {
        y += 1;
        sCount[s[y]] += 1;
      }

      while (x + 1 <= y && sCount[s[x]] - 1 >= tCount[s[x]]) {
        sCount[s[x]] -= 1;
        x += 1;
      }

      if (pred() && (returnS.empty() || y - x + 1 < int(returnS.size()))) {
        returnS = s.substr(x, y - x + 1);
      }
    }

    return returnS;
  }
};