class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    std::vector<int> left(nums.size(), 1);
    int p = 1;
    for (int i = 0; i < nums.size(); ++i) {
      left[i] = p;
      p *= nums[i];
    }

    std::vector<int> right(nums.size(), 1);
    p = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      right[i] = p;
      p *= nums[i];
    }

    for (int i = 0; i < nums.size(); ++i) {
      nums[i] = left[i] * right[i];
    }

    return nums;
  }
};
