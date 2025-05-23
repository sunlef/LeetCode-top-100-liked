// https://leetcode.cn/problems/set-matrix-zeroes
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();

    bool row0IsZero = false, col0IsZero = false;
    for (int j = 0; j < m; j++) {
      row0IsZero |= matrix[0][j] == 0;
    }
    for (int i = 0; i < n; i++) {
      col0IsZero |= matrix[i][0] == 0;
    }

    // matrix[...][0] and matrix[0][...] will become TAGs
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int j = 1; j < m; j++) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < n; i++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int i = 1; i < n; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < m; j++) {
          matrix[i][j] = 0;
        }
      }
    }

    if (row0IsZero) {
      for (int j = 0; j < m; j++) {
        matrix[0][j] = 0;
      }
    }
    if (col0IsZero) {
      for (int i = 0; i < n; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};