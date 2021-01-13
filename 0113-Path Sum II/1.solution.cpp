#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;

 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    backtrace(root, sum);
    return result;
  }

  void backtrace(TreeNode* root, int sum) {
    if (root == NULL)
      return;

    path.emplace_back(root->val);

    sum -= root->val;
    if (root->left == NULL && root->right == NULL) {
      if (sum == 0) {
        result.emplace_back(path);
      }
      path.pop_back();
      return;
    }

    if (root->left) {
      backtrace(root->left, sum);
    }

    if (root->right) {
      backtrace(root->right, sum);
    }

    path.pop_back();
  }
};