#include "../lib/ListNode.h"

using namespace std;

class Solution {
 private:
  ListNode* first;

 public:
  bool isPalindrome(ListNode* head) {
    first = head;
    return recursiveCheck(head);
  }

  bool recursiveCheck(ListNode* head) {
    if (head == NULL)
      return true;
    bool result = recursiveCheck(head->next);
    if (!result) return false;
    if (head->val != first->val)
      return false;

    first = first->next;
    return true;
  }
};