class Solution {
 public:
  vector<int> shuffle(vector<int> &nums, int n) {
    std::vector<int> res(n * 2, 0);
    int count = 0;
    for (int i = 0; i < res.size(); i += 2) {
      res[i] = nums[count++];
    }

    count = n;
    for (int i = 1; i < res.size(); i += 2) {
      res[i] = nums[count++];
    }
    return res;
  }
};

class Solution {
 public:
  vector<int> shuffle(vector<int> &nums, int n) {
    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
      res.push_back(nums[i]);
      res.push_back(nums[i + n]);
    }
    return res;
  }
};