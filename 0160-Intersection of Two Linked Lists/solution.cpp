#include "../lib/ListNode.h"

using namespace std;

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* p = headA;
    ListNode* q = headB;
    while (p != q) {
      p = p == NULL ? headB : p->next;
      q = q == NULL ? headA : q->next;
    }

    return p;
  }
};