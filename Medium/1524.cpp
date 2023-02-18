class Solution {
 public:
  int numOfSubarrays(vector<int> &arr) {
    int odd = 0;
    int even = 0;
    int ans = 0;
    for (const int &num : arr) {
      if (num % 2 == 0) {
        ++even;
      } else {
        swap(even, odd);
        ++odd;
      }

      ans = (ans + odd) % (int)(1e9 + 7);
    }

    return ans;
  }
};
