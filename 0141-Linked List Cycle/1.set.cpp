#include <set>
#include "../lib/ListNode.h"

using namespace std;

/*
最直观的做法就是使用 set 保存已经遍历过的节点，只要遍历到已经遍历过的节点就说明有环
*/
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    set<ListNode*> visited;
    ListNode* current = head;
    while (current != NULL) {
      if (visited.find(current) != visited.end()) {
        return true;
      }

      visited.emplace(current);
      current = current->next;
    }

    return false;
  }
};