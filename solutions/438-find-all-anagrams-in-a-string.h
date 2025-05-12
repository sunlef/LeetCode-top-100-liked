// https://leetcode.cn/problems/find-all-anagrams-in-a-string
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    std::map<char, int> pCount;
    for (char &c : p) {
      pCount[c] += 1;
    }

    int n = s.size();

    std::map<char, int> sCount;
    std::vector<int> returnV;
    for (int x = 0, y = -1; x < n; sCount[s[x]] -= 1, x++) {
      while (y + 1 < n && sCount[s[y + 1]] < pCount[s[y + 1]]) {
        y += 1;
        sCount[s[y]] += 1;
      }

      if (sCount == pCount) {
        returnV.push_back(x);
      }
    }

    return returnV;
  }
};