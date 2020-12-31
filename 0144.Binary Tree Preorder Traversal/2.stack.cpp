#include <stack>
#include <vector>
#include "../lib/TreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* top = stk.top();
      stk.pop();
      result.push_back(top->val);

      if (top->right != nullptr) {
        stk.push(top->right);
      }

      if (top->left != nullptr) {
        stk.push(top->left);
      }
    }

    return result;
  }
};

/*
执⾏⽤时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的⽤户
内存消耗： 8.6 MB , 在所有 C++ 提交中击败了 40.69% 的⽤户
*/