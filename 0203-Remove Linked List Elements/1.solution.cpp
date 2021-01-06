#include "../lib/ListNode.h"

using namespace std;

/**
 * 这种解法直接考虑 pre 为 NULL 的情况
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* pre = NULL;
    ListNode* current = head;
    while (current != NULL) {
      if (current->val == val) {
        if (pre == NULL) {
          head = current->next;
        } else {
          pre->next = current->next;
        }
      } else {
        pre = current;
      }
      current = current->next;
    }

    return head;
  }
};