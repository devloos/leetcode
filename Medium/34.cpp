class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int hi = nums.size() - 1;
    int lo = 0;

    if (lo == hi && nums[lo] == target) {
      return {lo, hi};
    }

    while (lo <= hi) {
      int mid = (hi + lo) / 2;
      if (nums[mid] == target) {
        return {findLowest(nums, mid, target), findHighest(nums, mid, target)};
      }

      if (nums[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return {-1, -1};
  }

  int findLowest(const std::vector<int> &nums, int mid, int target) {
    int res = mid;
    for (int i = mid; i >= 0 && (nums[i] == target); --i) {
      res = i;
    }

    return res;
  }

  int findHighest(const std::vector<int> &nums, int mid, int target) {
    int res = mid;
    for (int i = mid; i < nums.size() && (nums[i] == target); ++i) {
      res = i;
    }

    return res;
  }
};