#include "../lib/ListNode.h"

using namespace std;

/**
 * 使用一个伪头结点
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode();
    sentinel->next = head;

    ListNode* pre = sentinel;
    ListNode* current = sentinel->next;
    while (current != NULL) {
      if (current->val == val) {
        pre->next = current->next;
      } else {
        pre = current;
      }
      current = current->next;
    }

    return sentinel->next;
  }
};