#include <vector>
#include "../lib/BinaryTreeNode.h"

/*
应该用 DFS 而不是 BFS，除非退化成单链表 DFS 才和 BFS 相等
*/
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr)
      return false;

    bool isLeaf = root->left == nullptr && root->right == nullptr;
    if (isLeaf && sum - root->val == 0) {
      return true;
    }

    sum -= root->val;

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
  }
};