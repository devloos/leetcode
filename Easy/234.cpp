class Solution {
public:
    bool isPalindrome(ListNode* head) {
      std::vector<int> vec;
      ListNode* node = head;
      while (node != nullptr) {
        vec.push_back(node->val);
        node = node->next;
      }

      int l = 0;
      int r = vec.size() - 1;

      while (l < r) {
        if (vec[l] != vec[r]) {
          return false;
        }
        ++l;
        --r;
      }

      return true;
    }
};
