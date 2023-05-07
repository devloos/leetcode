class Solution {
 public:
  int n = 0;
  int m = 0;
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    int mav = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mav = max(mav, dfs(grid, i, j));
      }
    }

    return mav;
  }

  int dfs(vector<vector<int>> &g, int i, int j) {
    if (i >= m || j >= n || i < 0 || j < 0) {
      return 0;
    }

    if (g[i][j] != 1) {
      return 0;
    }

    g[i][j] = -1;

    return 1 + dfs(g, i + 1, j) + dfs(g, i, j + 1) + dfs(g, i - 1, j) + dfs(g, i, j - 1);
  }
};
