#include "../common/nodes.h"
#include <cstddef>

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;

    ListNode *p1 = list1, *p2 = list2;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val > p2->val) {
        cur->next = p2;
        p2 = p2->next;
      } else {
        cur->next = p1;
        p1 = p1->next;
      }

      cur = cur->next;
    }
    if (p1 != nullptr) {
      cur->next = p1;
    } else if (p2 != nullptr) {
      cur->next = p2;
    }

    return dummy->next;
  }

  ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2) {}
};
