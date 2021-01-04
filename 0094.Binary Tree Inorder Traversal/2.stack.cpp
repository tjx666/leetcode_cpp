#include <stack>
#include <vector>
#include "../lib/BinaryTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    stack<TreeNode*> stk;

    TreeNode* current = root;
    while (current != nullptr || !stk.empty()) {
      if (current != nullptr) {
        stk.push(current);
        current = current->left;
      } else {
        current = stk.top();
        stk.pop();
        result.push_back(current->val);
        current = current->right;
      }
    }

    return result;
  }
};
/*
执⾏⽤时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的⽤户
内存消耗： 8.6 MB , 在所有 C++ 提交中击败了 40.69% 的⽤户
*/