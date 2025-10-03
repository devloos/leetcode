class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
    std::vector<int> res(queries.size(), 0);
    int sum = 0;

    for (const auto &num : nums) {
      if (num % 2 == 0) {
        sum += num;
      }
    }

    for (int row = 0; row < queries.size(); ++row) {
      if (nums[queries[row][1]] % 2 == 0) {
        sum -= nums[queries[row][1]];
      }

      nums[queries[row][1]] += queries[row][0];

      if (nums[queries[row][1]] % 2 == 0) {
        sum += nums[queries[row][1]];
      }

      res[row] = sum;
    }

    return res;
  }
};