#include "../common/nodes.h"

class Solution {
public:
  ListNode *left;
  bool res = true;
  bool isPalindrome(ListNode *head) {
    (void)head;
    return false;
  }

  void traverse(ListNode *right) {
    (void)right;
  }
};

class Solution2 {
public:
  bool isPalindrome(ListNode *head) {
    (void)head;
    return false;
  }

  ListNode *reverse(ListNode *head) {
    (void)head;
    return nullptr;
  }
};
