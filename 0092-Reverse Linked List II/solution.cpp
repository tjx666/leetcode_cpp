#include "../lib/ListNode.h"

using namespace std;

/**
 * 由题目条件 "1 ≤ m ≤ n ≤ 链表长度。" 可知,
 */
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* sentinel = new ListNode();
    sentinel->next = head;
    ListNode* pre = sentinel;
    ListNode* current = head;
    // 找到第 m 个节点
    int i = 1;
    while (i != m) {
      pre = current;
      current = current->next;
      i++;
    }

    ListNode* preMNode = pre;
    ListNode* mNode = current;
    pre = current;
    // current 从下一个节点开始
    current = current->next;
    ListNode* next;
    i++;

    // 翻转 m 和 n 之间的节点
    while (current != NULL && i <= n) {
      next = current->next;
      current->next = pre;
      pre = current;
      current = next;
      i++;
    }

    // 处理翻转首尾
    preMNode->next = pre;
    mNode->next = current;
    
    return sentinel->next;
  }
};