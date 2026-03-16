# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root):
        if root == None:
            return [True, 0]

        [is_l_balanced, lh] = self.helper(root.left)
        [is_r_balanced, rh] = self.helper(root.right)

        is_balanced = is_l_balanced and is_r_balanced and abs(lh - rh) <= 1
        max_h = max(lh, rh) + 1

        return is_balanced, max_h

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True

        ggs = self.helper(root)

        return ggs[0]
