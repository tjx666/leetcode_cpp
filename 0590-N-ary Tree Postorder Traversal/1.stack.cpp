#include <set>
#include <stack>
#include <vector>
#include "../lib/NTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> result;

    if (root == nullptr)
      return result;

    stack<Node*> stk;
    stk.push(root);
    set<Node*> visited;

    while (!stk.empty()) {
      Node* top = stk.top();
      bool traveled = true;

      for (auto iter = top->children.rbegin(); iter != top->children.rend(); iter++) {
          if (*iter != nullptr && visited.find(*iter) == visited.end()) {
              traveled = false;
              stk.push(*iter);
          }
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
