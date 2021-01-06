#include "../lib/ListNode.h"

using namespace std;

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode* pre = head;
    ListNode* current = head->next;
    ListNode* next;

    while (current != NULL) {
      next = current->next;
      current->next = pre;
      pre = current;
      current = next;
    }

    head->next = NULL;

    return pre;
  }
};