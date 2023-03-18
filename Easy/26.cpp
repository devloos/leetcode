class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int left = 0;
    int right = 1;
    int i = 1;
    while (right < nums.size()) {
      if (nums[left] == nums[right]) {
        ++right;
      } else {
        nums[i++] = nums[right];
        left = right;
        ++right;
      }
    }

    return i;
  }
};
