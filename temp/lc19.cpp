#include "../problems/common/nodes.h"
#include <cstddef>

using namespace std;

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *node = findFromEnd(head, n + 1);

    node->next = node->next->next;

    return dummy->next;
  }

private:
  ListNode *findFromEnd(ListNode *head, int k) {
    ListNode *fast = head, *slow = head;

    for (int i = 0; i < k && fast != nullptr; i++) {
      fast = fast->next;
    }
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }
};