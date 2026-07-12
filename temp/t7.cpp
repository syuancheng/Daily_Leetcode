#include "../problems/common/nodes.h"
#include <vector>

class Solution {
public:
  ListNode *reverseN(ListNode *head, int n) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *pre = nullptr, *cur = head, *next = head->next;
    while (n > 0) {
      cur->next = pre;
      pre = cur;
      cur = next;
      if (next != nullptr) {
        next = next->next;
      }
      n--;
    }
    head->next = cur;

    return pre;
  }
};