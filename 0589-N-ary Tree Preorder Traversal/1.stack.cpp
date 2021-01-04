#include <stack>
#include <vector>
#include "../lib/NTreeNode.h"

using namespace std;

/*
    递归解法太简单就不写了
*/
class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    stack<Node*> stk;
    stk.push(root);

    while (!stk.empty()) {
      Node* top = stk.top();
      stk.pop();
      result.push_back(top->val);
      for (auto iter = top->children.rbegin(); iter != top->children.rend(); iter++) {
        stk.push(*iter);
      }
    }
    return result;
  }
};