#include "../common/nodes.h"

class Solution {
private:
  ListNode *reverseN(ListNode *head, int n) {
    ListNode *prev = nullptr;
    ListNode *cur = head;

    while (cur != nullptr && n > 0) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      n--;
    }
    head->next = cur;

    return prev;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *tail = head;
    for (int i = 0; i < k; i++) {
      if (tail == nullptr) {
        return head;
      }
      tail = tail->next;
    }

    ListNode *newHead = reverseN(head, k);
    head->next = reverseKGroup(tail, k);
    return newHead;
  }
};
