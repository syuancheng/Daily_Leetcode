#include "../common/nodes.h"
#include <cstddef>
#include <vector>

/**
234. 回文链表
*/
class Solution {
public:
  ListNode *left;
  bool res = true;
  bool isPalindrome(ListNode *head) {
    left = head;
    traverse(head);
    return res;
  }

  void traverse(ListNode *right) {
    if (right == nullptr) {
      return;
    }
    traverse(right->next);
    if (left->val != right->val) {
      res = false;
    }
    left = left->next;
  }
};