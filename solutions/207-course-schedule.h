// https://leetcode.cn/problems/course-schedule
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    const int &n = numCourses;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> d(n);

    for (auto const &pi : prerequisites) {
      int u = pi[1];
      int v = pi[0];

      adj[u].push_back(v);
      d[v] += 1;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
      if (d[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (--d[v] == 0) {
          q.push(v);
        }
      }
    }

    return *std::ranges::max_element(d) == 0;
  }
};