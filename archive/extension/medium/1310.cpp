class Solution {
 public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    for (int i = 1; i < arr.size(); ++i) {
      arr[i] ^= arr[i - 1];
    }

    std::vector<int> res(queries.size(), 0);
    for (int i = 0; i < queries.size(); ++i) {
      int left = queries[i][0] - 1;
      int right = queries[i][1];
      if (left < 0) {
        res[i] = arr[right];
      } else {
        res[i] = arr[right] ^ arr[left];
      }
    }

    return res;
  }
};