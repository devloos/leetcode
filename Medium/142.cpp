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
  ListNode* detectCycle(ListNode* head) {
    std::unordered_map<ListNode*, int> map;
    ListNode* node = head;

    while (node != nullptr) {
      ++map[node];
      if (map[node] > 1) {
        return node;
      }

      node = node->next;
    }

    return nullptr;
  }
};
