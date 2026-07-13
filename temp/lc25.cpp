#include "../problems/common/nodes.h"

class Solution {
public:
  ListNode *reverseN(ListNode *head, int n) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *pre = nullptr, *cur = head, *nxt = head->next;
    while (cur != nullptr && n > 0) {
      cur->next = pre;
      pre = cur;
      cur = nxt;
      if (nxt != nullptr) {
        nxt = nxt->next;
      }
      n--;
    }
    head->next = cur;

    return pre;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return head;
    }
    ListNode *a, *b;
    a = b = head;
    for (int i = 0; i < k; i++) {
      if (b == nullptr) {
        return head;
      }
      b = b->next;
    }
    ListNode *newHead = reverseN(a, k);
    a->next = reverseKGroup(b, k);
    return newHead;
  }
};