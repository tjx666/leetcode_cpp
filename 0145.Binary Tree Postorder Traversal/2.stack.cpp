#include <stack>
#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

/*
前序遍历：root -> left -> right
后序遍历：left -> right -> root
如果按照：root -> right -> left 顺序遍历得到的就是后序遍历的逆序
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* top = stk.top();
      stk.pop();
      result.push_back(top->val);

      if (top->left != nullptr) {
        stk.push(top->left);
      }

      if (top->right != nullptr) {
        stk.push(top->right);
      }
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
