#include "../common/nodes.h"

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *dummy1 = new ListNode(-1);
    ListNode *dummy2 = new ListNode(-1);

    ListNode *p1 = dummy1, *p2 = dummy2;
    ListNode *p = head;

    while (p != nullptr) {
      if (p->val < x) {
        p1->next = p;
        p1 = p1->next;
      } else {
        p2->next = p;
        p2 = p2->next;
      }
      ListNode *tmp = p->next;
      p->next = nullptr;
      p = tmp;
    }
    p1->next = dummy2;

    return dummy1->next;
  }
};
