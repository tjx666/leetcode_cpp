#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

/*
 * 非递归的解法也很简单，遍历每一个节点反转左右子节点即可
 */
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
      return root;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};