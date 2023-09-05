#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>

int main() {
  int n = 0;
  int k = 0;

  std::cin >> n >> k;
  std::map<int, int> nums;

  for (int i = 0; i < n; ++i) {
    int num = 0;
    std::cin >> num;
    // increase
    nums[num] += 1;
    // decrease because it ends here
    nums[num + 1000] += -1;
  }

  int m = 0;
  int sum = 0;
  for (const auto &pair : nums) {
    sum += pair.second;
    m = std::max(m, sum);
  }

  // rounding up
  std::cout << (m + k - 1) / k << "\n";

  return 0;
}