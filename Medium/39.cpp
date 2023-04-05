class Solution {
 public:
  int target = 0;
  vector<vector<int>> combinationSum(vector<int> &candidates, int t) {
    target = t;
    vector<vector<int>> res;
    vector<int> m;
    recursive(res, m, candidates, 0, 0);
    return res;
  }

  void recursive(
      vector<vector<int>> &res, vector<int> m, const vector<int> &can, int i, int sum) {
    if (sum > target) {
      return;
    }

    if (sum == target) {
      res.push_back(m);
      return;
    }

    for (int j = i; j < can.size(); ++j) {
      m.push_back(can[j]);
      sum += can[j];
      recursive(res, m, can, j, sum);
      m.pop_back();
      sum -= can[j];
    }
  }
};
