class NumMatrix {
 public:
  std::vector<std::vector<int>> matrix;

 public:
  NumMatrix(std::vector<std::vector<int>> &m) : matrix(m) {
    for (auto &row : matrix) {
      for (int i = 1; i < row.size(); ++i) {
        row[i] += row[i - 1];
      }
    }

    for (int col = 0; col < matrix[0].size(); ++col) {
      for (int row = 1; row < matrix.size(); ++row) {
        matrix[row][col] += matrix[row - 1][col];
      }
    }
  }

  int sumRegion(int r1, int c1, int r2, int c2) {
    int total = matrix[r2][c2];
    int extra = 0;

    if (c1 - 1 >= 0) {
      extra += matrix[r2][c1 - 1];
    }

    if (r1 - 1 >= 0) {
      extra += matrix[r1 - 1][c2];
    }

    if (r1 - 1 >= 0 && c1 - 1 >= 0) {
      extra -= matrix[r1 - 1][c1 - 1];
    }

    return total - extra;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(r1,c1,r2,c2);
 */