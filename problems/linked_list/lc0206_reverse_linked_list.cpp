#include "../common/nodes.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *pre = nullptr, *cur = head, *next = head->next;

    while (cur != nullptr) {
      cur->next = pre;
      pre = cur;
      cur = next;
      if (next != nullptr) {
        next = next->next;
      }
    }
    return pre;
  }
};


class Solution2 {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }
};