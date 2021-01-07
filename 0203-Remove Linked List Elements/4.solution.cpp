#include "../lib/ListNode.h"

using namespace std;

/**
 * 先处理前面连续的需要被删除的节点
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL)
      return NULL;

    if (head->val == val) {
      return removeElements(head->next, val);
    } else {
      head->next = removeElements(head->next, val);
      return head;
    }
  }
};