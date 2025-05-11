#include "1-two-sum.h"
#include "debug.h"

int main() {
  std::vector<int> v = {2, 7, 11, 5};
  int target = 9;

  auto res = Solution().twoSum(v, target);
  debug(res);
  return 0;
}