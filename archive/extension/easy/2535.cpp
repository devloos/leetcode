class Solution {
 public:
  int differenceOfSum(vector<int> &nums) {
    int elementSum = 0;
    int digitSum = 0;
    for (const int &val : nums) {
      elementSum += val;
      std::string digits = std::to_string(val);
      for (const char &c : digits) {
        digitSum += c - '0';
      }
    }

    return abs(elementSum - digitSum);
  }
};