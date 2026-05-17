#include "type.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode* pre = dummy;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val > list2->val) {
        pre->next = list2;
        list2 = list2->next;
      } else {
        pre->next = list1;
        list1 = list1->next;
      }
      pre = pre->next;
    }

    if (list1) {
      pre->next = list1;
    }
    if (list2) {
      pre->next = list2;
    }
    return dummy->next;
  }
};
