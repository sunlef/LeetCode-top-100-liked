// https://leetcode.cn/problems/rotting-oranges

#include <ranges>

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    using T = std::pair<int, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> q;

    std::vector<int> dist(n * m, std::numeric_limits<int>::max());
    std::vector<int> save;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          dist[i * m + j] = 0;
          q.emplace(0, i * m + j);
        } else if (grid[i][j] == 1) {
          save.push_back(i * m + j);
        }
      }
    }
    auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };
    std::vector<std::pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
      auto [distance, p] = q.top();
      q.pop();

      int x = p / m, y = p % m;
      for (auto [dx, dy] : moves) {
        int nx = x + dx;
        int ny = y + dy;
        if (valid(nx, ny) && grid[nx][ny] == 1 && dist[nx * m + ny] > distance + 1) {
          dist[nx * m + ny] = distance + 1;
          q.emplace(distance + 1, nx * m + ny);
        }
      }
    }

    if (save.empty()) {
      return 0;
    }
    for (auto x : save) {
      if (dist[x] == std::numeric_limits<int>::max()) {
        return -1;
      }
    }

    return std::ranges::max(save | std::views::transform([&dist](int x) { return dist[x]; }));
  }
};