#include <vector>
#include "../lib/TreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    recursive(root, result);
    return result;
  }

  void recursive(TreeNode* node, vector<int>& result) {
    if (node == nullptr) {
      return;
    }
    recursive(node->left, result);
    recursive(node->right, result);
    result.push_back(node->val);
  }
};