#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    recursive(root, result);
    return result;
  }

  void recursive(TreeNode* node, vector<int>& result) {
    if (node == nullptr) {
      return;
    }
    result.push_back(node->val);
    recursive(node->left, result);
    recursive(node->right, result);
  }
};