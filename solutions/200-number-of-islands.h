// https://leetcode.cn/problems/number-of-islands
class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();

    std::vector<std::pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    std::vector<int> visited(n * m);
    auto valid = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m && visited[m * x + y] == 0 && grid[x][y] == '1';
    };

    auto dfs = [&](auto &&self, int p, int id) -> void {
      int x = p / m, y = p % m;
      visited[p] = id;
      for (auto &[dx, dy] : moves) {
        int nx = x + dx;
        int ny = y + dy;
        if (valid(nx, ny)) {
          self(self, m * nx + ny, id);
        }
      }
    };

    int cnt = 0;
    for (int i = 0; i < n * m; i++) {
      if (grid[i / m][i % m] == '1' && visited[i] == 0) {
        dfs(dfs, i, ++cnt);
      }
    }
    return cnt;
  }
};