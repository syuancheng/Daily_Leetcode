#include "type.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *head1 = list1, *head2 = list2;

    ListNode *pre = dummy;

    while (head1 != nullptr && head2 != nullptr) {
      if (head1->val <= head2->val) {
        pre->next = head1;

        head1 = head1->next;
      } else {
        pre->next = head2;
        head2 = head2->next;
      }
      pre = pre->next;
    }

    if (head1 != nullptr) {
      pre->next = head1;
    } else if (head2 != nullptr) {
      pre->next = head2;
    }

    return dummy->next;
  }
};