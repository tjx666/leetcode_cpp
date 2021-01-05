#include <queue>
#include <vector>
#include "../lib/NTreeNode.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (root == nullptr)
      return result;

    queue<Node*> que;
    que.push(root);

    while (!que.empty()) {
      vector<int> level;
      size_t level_count = que.size();
      for (size_t i = 0; i < level_count; i++) {
        Node* front = que.front();
        que.pop();
        level.push_back(front->val);

        for (auto child : front->children) {
          que.push(child);
        }
      }
      result.push_back(level);
    }

    return result;
  }
};