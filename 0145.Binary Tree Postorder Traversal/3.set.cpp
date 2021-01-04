#include <stack>
#include <vector>
#include <set>
#include "../lib/TreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    stack<TreeNode*> stk;
    stk.push(root);
    set<TreeNode*> visited;

    while (!stk.empty()) {
      TreeNode* top = stk.top();
      bool traveled = true;

      if (top->right != nullptr && visited.find(top->right) == visited.end()) {
          traveled = false;
          stk.push(top->right);
      } 

      if (top->left != nullptr && visited.find(top->left) == visited.end()) {
          traveled = false;
          stk.push(top->left);
      }

      if (traveled) {
          result.push_back(top->val);
          stk.pop();
          visited.insert(top);
      }
    }

    return result;
  }
};
