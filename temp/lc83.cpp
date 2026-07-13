#include "../problems/common/nodes.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
      if (fast->val != slow->val) {
        slow->next = fast;
        slow = slow->next;
      }
      fast = fast->next;
    }
    slow->next = nullptr;
    return head;
  }
};