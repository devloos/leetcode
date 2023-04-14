class Solution {
 public:
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return helper(nums, 0, dp);
  }

  int helper(vector<int> &nums, int idx, vector<int> &dp) {
    if (idx >= nums.size()) {
      return 0;
    }

    if (dp[idx] != -1) {
      return dp[idx];
    }

    dp[idx] = max(helper(nums, idx + 1, dp), nums[idx] + helper(nums, idx + 2, dp));
    return dp[idx];
  }
};

// move 2 until end
// come back move 1

// stack 1:
// r = 2
// idx = 0

// stack 2:
// r = 2
// idx = 2
// i = 3

// [2,7,9,3,1,4,5,7,2,4]
// [25,19,21,17,14,12,10,11,7,2]

// odd
