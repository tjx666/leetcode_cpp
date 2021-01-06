#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(){};
  explicit ListNode(int x)
      : val(x), next(NULL) {}
};
