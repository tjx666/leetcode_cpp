#include <queue>
#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr)
      return result;

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
      vector<int> level;
      size_t level_count = que.size();
      for (size_t i = 0; i < level_count; i++) {
        TreeNode* front = que.front();
        que.pop();
        level.push_back(front->val);

        if (front->left != nullptr) {
          que.push(front->left);
        }

        if (front->right != nullptr) {
          que.push(front->right);
        }
      }
      result.push_back(level);
    }

    return result;
  }
};