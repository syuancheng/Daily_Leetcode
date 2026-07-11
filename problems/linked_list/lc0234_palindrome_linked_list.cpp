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

class Solution2 {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast != nullptr) {
      slow = slow->next;
    }

    ListNode *left = head;
    ListNode *right = reverse(slow);
    while (right != nullptr) {
      if (left->val != right->val) {
        return false;
      }
      right = right->next;
      left = left->next;
    }

    return true;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur != nullptr) {
      ListNode *next = cur->next;

      cur->next = pre;
      pre = cur;

      cur = next;
    }

    return cur;
  }
};