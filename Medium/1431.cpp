class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int> &candies, int e) {
    std::vector<bool> res;

    int max = 0;
    for (const auto &candy : candies) {
      if (candy > max) {
        max = candy;
      }
    }

    for (const auto &candy : candies) {
      if (candy + e >= max) {
        res.push_back(true);
      } else {
        res.push_back(false);
      }
    }

    return res;
  }
};