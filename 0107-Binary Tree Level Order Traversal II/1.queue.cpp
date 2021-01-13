#include <queue>
#include <vector>
#include <algorithm>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL)
      return result;

    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      size_t level_size = que.size();
      vector<int> level(level_size);
      for (size_t i = 0; i < level_size; i++) {
        TreeNode* front = que.front();
        level[i] = front->val;
        que.pop();
        if (front->left != NULL) {
          que.push(front->left);
        }

        if (front->right != NULL) {
          que.push(front->right);
        }
      }
      result.push_back(level);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};