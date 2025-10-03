class Solution {
 public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT_MAX;
    int left = 0;

    int sum = 0;
    for (int right = 0; right < nums.size(); ++right) {
      sum += nums[right];

      while (sum >= target) {
        res = min(res, right - left + 1);
        sum -= nums[left++];
      }
    }

    return (res == INT_MAX) ? 0 : res;
  }
};