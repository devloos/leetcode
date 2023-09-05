#include <iostream>
#include <limits>
#include <queue>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n >> k;
  std::vector<int> nums;

  for (int i = 0; i < n; ++i) {
    int num = 0;
    std::cin >> num;
    nums.push_back(num);
  }

  // std::vector<int> nums = {1000, 1010, 1500, 1999, 2000, 2010, 2999};
  std::queue<int> q;

  int m = 0;
  int sum = 1;
  for (int i = 1; i < nums.size(); ++i) {
    q.push(nums[i - 1]);
    std::queue<int> temp(q);
    while (temp.size() > 0) {
      if (q.front() + 1000 <= nums[i]) {
        --sum;
        q.pop();
      }
      temp.pop();
    }
    m = std::max(m, ++sum);
  }

  std::cout << (m + k - 1) / k << "\n";

  return 0;
}