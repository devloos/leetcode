class Solution {
 public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
    for (int i = 0; i < score.size(); ++i) {
      int max_i = i;
      for (int j = i; j < score.size(); ++j) {
        if (score[j][k] > score[max_i][k]) {
          max_i = j;
        }
      }

      auto temp = score[i];
      score[i] = score[max_i];
      score[max_i] = temp;
    }

    return score;
  }
};