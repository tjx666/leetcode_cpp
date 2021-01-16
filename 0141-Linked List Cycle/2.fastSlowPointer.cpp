#include <set>
#include "../lib/ListNode.h"

using namespace std;

/*
如果有环的话，每次走 2 步的快指针肯定会在某一刻和每次走一步的慢指针重合
时间复杂度 n
空间复杂度：0
*/
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (head == NULL) {
      return false;
    }

    ListNode* sentinel = new ListNode();
    sentinel->next = head;
    ListNode* fast = head;
    ListNode* slow = sentinel;

    while (fast != NULL && fast->next != NULL && slow != NULL) {
      if (fast == slow)
        return true;
      slow = slow->next;
      fast = fast->next->next;
    }

    delete sentinel;
    return false;
  }
};