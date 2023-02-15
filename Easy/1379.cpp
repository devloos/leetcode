/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    return findNode(cloned, target);
  }

  TreeNode* findNode(TreeNode* head, TreeNode* target) {
    if (head == nullptr) {
      return nullptr;
    }

    if (head->val == target->val) {
      return head;
    }

    TreeNode* left = findNode(head->left, target);
    if (left != nullptr && left->val == target->val) {
      return left;
    }

    TreeNode* right = findNode(head->right, target);
    if (right != nullptr && right->val == target->val) {
      return right;
    }

    return nullptr;
  }
};