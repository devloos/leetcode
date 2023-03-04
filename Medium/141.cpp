/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      // I LIKE THIS APPROACH BECAUSE IT IS MORE INTUITIVE
      // std::unordered_map<ListNode*, int> map;
      // ListNode* node = head;
      // while (node != nullptr) {
      //   ++map[node];
      //   if (map[node] > 1) {
      //     return true;
      //   }

      //   node = node->next;
      // }

      // return false;

      if (head == nullptr) {
        return false;
      }

      ListNode* fast = head;
      ListNode* slow = head;

      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
          return true;
        }
      }

      return false;
    }
};
