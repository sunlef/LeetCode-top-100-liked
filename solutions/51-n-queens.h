// https://leetcode.cn/problems/n-queens
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> returnV;

    std::set<int> col, main_diag, anti_diag;

    auto set_occupy_status = [&](int x, int y, bool status) {
      if (status == true) {
        col.insert(y);
        main_diag.insert(x + y);
        anti_diag.insert(x - y);
      } else {
        col.erase(y);
        main_diag.erase(x + y);
        anti_diag.erase(x - y);
      }
    };
    auto is_occupied = [&](int x, int y) {
      return col.contains(y) || main_diag.contains(x + y) || anti_diag.contains(x - y);
    };

    auto dfs = [&](auto &&self, int step) {
      if (step == n) {
        returnV.emplace_back(board);
        return;
      }

      for (int j = 0; j < n; j++) {
        if (!is_occupied(step, j)) {
          set_occupy_status(step, j, true);
          board[step][j] = 'Q';
          self(self, step + 1);
          set_occupy_status(step, j, false);
          board[step][j] = '.';
        }
      }
    };

    dfs(dfs, 0);
    return returnV;
  }
};