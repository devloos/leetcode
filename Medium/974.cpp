class Solution {
public:
    void createPrefix(const std::vector<int> &nums, std::vector<int> &prefix) {
      prefix.push_back(nums[0]);
      for (int i = 1; i < nums.size(); ++i) {
        prefix.push_back(nums[i] + prefix[i - 1]);
      }
    }

    int subarraysDivByK(vector<int>& nums, int k) {
      std::vector<int> prefix;
      createPrefix(nums, prefix);

      std::map<int, int> map; 
      int prefixMod = 0;
      for (const auto &val : prefix) {
        prefixMod = (val % k + k) % k;
        ++map[prefixMod];
        std::cout << prefixMod << "\n";
      }

      int sum = 0;
      std::map<int, int> prevFact;
      for (int i = 0; i < k; ++i) {
        if (i == 0) {
          sum += (map[i] * (map[i] - 1)) / 2 + map[i];
          continue;
        }
        sum += (map[i] * (map[i] - 1)) / 2;
      }
      
      return sum;
    }
};
