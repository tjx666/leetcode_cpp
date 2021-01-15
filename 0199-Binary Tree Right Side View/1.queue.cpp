#include <queue>
#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;
    
    queue<TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
      size_t level_size = que.size();
      for (size_t i = 0; i < level_size; i++) {
        TreeNode* front = que.front();
        que.pop();
        if (front->left) {
          que.emplace(front->left);
        }

        if (front->right) {
          que.emplace(front->right);
        }

        if (i == level_size - 1) {
          result.emplace_back(front->val);
        }
      }
    }

    return result;
  }
};