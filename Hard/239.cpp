class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    std::map<int, int> sub;
    for (int j = 0; j < k; ++j) {
      ++sub[nums[j]];
    }

    std::vector<int> res;
    res.push_back((sub.rbegin())->first);
    for (int i = k; i < nums.size(); ++i) {
      --sub[nums[i - k]];
      ++sub[nums[i]];
      if (sub[nums[i - k]] <= 0) {
        sub.erase(nums[i - k]);
      }
      res.push_back((sub.rbegin())->first);
    }

    return res;
  }
};