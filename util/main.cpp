#include "279-perfect-squares.h"

int main() {
  std::vector<int> v = {0, 1, 2, 0, 3, 4, 5, 2, 1, 3, 1, 5};

  std::vector<std::vector<int>> vv = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

  std::string s = "aab";

  // auto res = Solution().setZeroes(vv);
  // Solution().setZeroes(vv);
  // debug(Solution().orangesRotting(vv));
  // debug(res);

  int n = 12;
  Solution().numSquares(n);
  return 0;
}