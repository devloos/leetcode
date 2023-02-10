#include "main.h"

std::vector<int> diffArray(
    std::vector<int> nums, std::vector<std::vector<int>> queries, int value) {
  std::vector<int> ans(nums);
  for (int i = 1; i < ans.size(); ++i) {
    ans[i] = nums[i] - nums[i - 1];
  }

  for (const auto &query : queries) {
    ++ans[query[0]];
    if (query[1] < ans.size()) {
      --ans[query[1] + 1];
    }
  }

  for (int i = 1; i < ans.size(); ++i) {
    ans[i] += ans[i - 1];
  }

  return ans;
}

int main() {
  std::vector<int> nums = {3, 1, -2, 5, 4, 10};
  std::vector<std::vector<int>> queries = {{0, 4}, {1, 2}, {3, 5}, {0, 3}};
  int value = 1;

  auto res = diffArray(nums, queries, value);

  return 0;
}