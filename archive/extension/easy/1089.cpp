class Solution {
 public:
  void duplicateZeros(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == 0) {
        int t = nums[i];
        nums[i] = 0;
        for (int j = i + 1; j < nums.size(); ++j) {
          swap(t, nums[j]);
        }
        ++i;
      }
    }
  }
};
