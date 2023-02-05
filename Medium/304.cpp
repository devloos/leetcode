class NumMatrix {
 public:
  std::vector<std::vector<int>> matrix;

 public:
  NumMatrix(std::vector<std::vector<int>> &m) : matrix(m) {
    if (matrix.empty()) {
      return;
    }

    for (auto &row : matrix) {
      for (int i = 1; i < matrix.size(); ++i) {
        row[i] += row[i - 1];
      }
    }

    for (int col = 0; col < matrix.size(); ++col) {
      for (int row = 1; row < matrix.size(); ++row) {
        matrix[row][col] += matrix[row - 1][col];
      }
    }

    // matrix.insert(matrix.begin(), std::vector<int>(matrix.size(), 0));
    // for (auto &row : matrix) {
    //   row.insert(row.begin(), 0);
    // }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    // if (row1 == row2 && col1 == col2) {
    //   return matrix[row1][col1];
    // }
    return matrix[row2][col2] - matrix[row1][col2] - matrix[row2][col1] +
           matrix[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */