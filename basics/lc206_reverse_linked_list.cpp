#include "type.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *dummy = new ListNode();
    ListNode *curr = head;

    while (curr != nullptr) {
      auto *tmp = curr->next;

      curr->next = dummy->next;
      dummy->next = curr;

      curr = tmp;
    }
    return dummy->next;
  }
};