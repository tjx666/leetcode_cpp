#include "../lib/ListNode.h"

using namespace std;

/*
只需要考虑末尾连续的 9 即可。
例如: 12399
末尾没有 9 的只需要把最后一个数 + 1
*/
class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    ListNode* sentinel = new ListNode();
    sentinel->val = 0;
    sentinel->next = head;
    ListNode* previous = sentinel;
    ListNode* current = head;
    ListNode* pre9 = NULL;

    while (current != NULL) {
      if (current->val == 9) {
        if (pre9 == NULL) {
          pre9 = previous;
        }
      } else {
        pre9 = NULL;
      }
      previous = current;
      current = current->next;
    }

    if (pre9 != NULL) {
      pre9->val += 1;
      current = pre9->next;
      while (current != NULL) {
        current->val = 0;
        current = current->next;
      }
      return pre9 == sentinel ? sentinel : head;
    } else {
      previous->val += 1;
      return head;
    }
  }
};
;