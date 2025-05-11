/**
 * @brief https://leetcode.cn/problems/group-anagrams
 *
 */
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::map<std::string, std::vector<std::string>> group;

    std::ranges::for_each(strs, [&group](auto &str) {
      auto sorted = str;
      std::ranges::sort(sorted);
      group[sorted].emplace_back(str);
    });

    std::vector<std::vector<std::string>> returnV;
    std::ranges::for_each(
        group, [&returnV](auto &gi) { returnV.emplace_back(gi.second); });
    return returnV;
  }
};