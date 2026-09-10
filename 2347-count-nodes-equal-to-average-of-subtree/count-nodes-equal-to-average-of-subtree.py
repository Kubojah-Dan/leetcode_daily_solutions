# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        matching_nodes = 0

        def dfs(node):
            nonlocal matching_nodes

            if not node:
                return 0, 0

            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)

            current_sum = left_sum + right_sum + node.val
            current_count = left_count + right_count + 1

            if current_sum // current_count == node.val:
                matching_nodes += 1

            return current_sum, current_count

        dfs(root)
        return matching_nodes