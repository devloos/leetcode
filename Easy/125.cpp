class Solution {
public:
    bool isPalindrome(string s) {
      int left = 0;
      int right = s.size() - 1;

      while (left < right) {
        if (!std::isalnum(s[left])) {
          ++left;
        } else if (!std::isalnum(s[right])) {
          --right;
        } else {
          if (std::toupper(s[left++]) != std::toupper(s[right--])) {
            return false;
          }
        }
      }

      return true;
    }
};
