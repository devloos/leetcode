class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    int res = 0;
    std::unordered_map<int, int> map;
    int sum = 0;
    ++map[0];
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (map.count(sum - k) > 0) {
        res += map[sum - k];
      }

      ++map[sum];
    }
    return res;
  }
};