class Solution {
 public:
  vector<int> addToArrayForm(vector<int> &nums, int k) {
    int c = nums.size() - 1;
    int r = 0;
    while (k > 0 && c >= 0) {
      r = k % 10;
      k /= 10;

      nums[c] += r;
      if (nums[c] > 9) {
        k += nums[c] / 10;
        nums[c] = nums[c] % 10;
      }
      --c;
    }

    // handling the increase in digits
    while (k > 0) {
      r = k % 10;
      k /= 10;
      nums.insert(nums.begin(), r);
    }

    return nums;
  }
};