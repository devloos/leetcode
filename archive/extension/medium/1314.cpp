class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    // prefix sum rows
    for (auto &row : mat) {
      for (int i = 1; i < row.size(); ++i) {
        row[i] += row[i - 1];
      }
    }

    // 2d prefix sum
    int n = mat.size();
    int m = mat[0].size();
    for (int col = 0; col < m; ++col) {
      for (int row = 1; row < n; ++row) {
        mat[row][col] += mat[row - 1][col];
      }
    }

    std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int r1 = max(0, i - k);
        int r2 = min(n - 1, i + k);
        int c1 = max(0, j - k);
        int c2 = min(m - 1, j + k);

        int total = mat[r2][c2];
        int extra = 0;

        if (c1 - 1 >= 0) {
          extra += mat[r2][c1 - 1];
        }

        if (r1 - 1 >= 0) {
          extra += mat[r1 - 1][c2];
        }

        if (r1 - 1 >= 0 && c1 - 1 >= 0) {
          extra -= mat[r1 - 1][c1 - 1];
        }

        res[i][j] = total - extra;
      }
    }

    return res;
  }
};
