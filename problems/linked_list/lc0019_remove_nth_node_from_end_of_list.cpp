#include "../common/nodes.h"

class Solution {
private:
  ListNode *findFromEnd(ListNode *head, int k) {
    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 0; i < k && fast != nullptr; i++) {
      fast = fast->next;
    }
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }

public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0, head);
    ListNode *node = findFromEnd(&dummy, n + 1);
    node->next = node->next->next;
    return dummy.next;
  }
};
