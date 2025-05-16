// https://leetcode.cn/problems/letter-combinations-of-a-phone-number

class Solution {
  std::map<char, std::string> f;

 public:
  Solution() {
    f['2'] = "abc";
    f['3'] = "def";
    f['4'] = "ghi";
    f['5'] = "jkl";
    f['6'] = "mno";
    f['7'] = "pqrs";
    f['8'] = "tuv";
    f['9'] = "wxyz";
  }

  vector<string> letterCombinations(string digits) {
    std::vector<std::string> returnV;

    std::string res;
    auto dfs = [&](auto &&self, int step) -> void {
      if (step == int(digits.size())) {
        if (!res.empty()) {
          returnV.push_back(res);
        }
        return;
      }

      for (auto ch : f[digits[step]]) {
        res.push_back(ch);
        self(self, step + 1);
        res.pop_back();
      }
    };

    dfs(dfs, 0);
    return returnV;
  }
};