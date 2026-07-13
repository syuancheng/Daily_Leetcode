#include "../common/nodes.h"

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == 1) {
      return reverseN(head, right);
    }
    ListNode *pre = head;
    for (int i = 1; i < left - 1; i++) {
      pre = pre->next;
    }
    pre->next = reverseN(pre->next, right - left + 1);
    return head;
  }

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
};

class Solution2 {
  // 后驱节点
  ListNode *successor = nullptr;

public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == 1) {
      return reverseN(head, right);
    }

    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
  }

  ListNode *reverseN(ListNode *head, int n) {
    if (n== 1) {
      successor = head->next;
      return head;
    }

    ListNode *last = reverseN(head, n - 1);
    head->next->next = head;
    head->next = successor;

    return last;
  }
};