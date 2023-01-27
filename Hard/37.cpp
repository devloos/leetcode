class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char c) {
      
      for (int j = 0; j < board.size(); j++) {
        if (board[row][j] == c) {
          return false;
        }
      }
      
      for (int j = 0; j < board.size(); j++) {
        if (board[j][col] == c) {
          return false;
        }
      }
      
      int sgc = (col / 3) * 3;
      int sgr = (row / 3) * 3;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[sgr + i][sgc + j] == c) {
            return false;
          }
        }
      }

      return true;
    }
  
    bool isSolution(vector<vector<char>>& board) {
      for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board.size(); col++) {
          if (board[row][col] == '.') {
            for (char c = '1'; c <= '9'; c++) {
              if (isSafe(board, row, col, c)) {
                board[row][col] = c;
                if (isSolution(board)) {
                  return true;
                }
                board[row][col] = '.';
              }
            }
            return false;
          }
        }
      }
      
      return true;
    }
  
    void solveSudoku(vector<vector<char>>& board) {
      isSolution(board);
    }
};
