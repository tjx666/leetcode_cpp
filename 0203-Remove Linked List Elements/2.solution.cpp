#include "../lib/ListNode.h"

using namespace std;

/**
 * 先处理前面连续的需要被删除的节点
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    while (head != NULL && head->val == val) {
      head = head->next;
    }

    if (head == NULL)
      return NULL;

    ListNode* pre = head;
    ListNode* current = head->next;
    while (current != NULL) {
      if (current->val == val) {
        pre->next = current->next;
      } else {
          pre = current;
      }
      current = current->next;
    }

    return head;
  }
};