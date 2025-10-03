class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    std::string result;
    int i = 0;
    for (const char &chara : strs[0]) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != chara) {
          return result;
        }
      }
      result += chara;
      ++i;
    }
    return result;
  }
};
