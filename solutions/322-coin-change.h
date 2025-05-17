// https://leetcode.cn/problems/coin-change
class Solution {  //
 public:
  int coinChange(vector<int> &coins, int amount) {
    constexpr int INF = std::numeric_limits<int>::max() / 2;

    std::vector<int> save(amount + 1, -1);
    save[0] = 0;

    auto dp = [&](auto &&self, int S) -> int {
      if (save[S] != -1) {
        return save[S];
      }

      int res = INF;
      for (int x : coins) {
        if (S - x >= 0) {
          res = std::min(res, self(self, S - x) + 1);
        }
      }
      return save[S] = res;
    };

    return dp(dp, amount) == INF ? -1 : dp(dp, amount);
  }
};