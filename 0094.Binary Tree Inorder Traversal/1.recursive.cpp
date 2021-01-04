#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    recursive(root, result);
    return result;
  }

  void recursive(TreeNode* node, vector<int>& result) {
    if (node == nullptr) {
      return;
    }
    recursive(node->left, result);
    result.push_back(node->val);
    recursive(node->right, result);
  }
};