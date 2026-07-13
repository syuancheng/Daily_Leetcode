#include "../problems/common/nodes.h"

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

class Solution2 {
private:
  // 后驱节点,比如反转前两个节点，那就记录的第三个节点
  ListNode *successor = nullptr;

public:
  ListNode *reverseN(ListNode *head, int n) {
    if (n == 1) {
      successor = head->next;
      return head;
    }

    ListNode *last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = successor;

    return last;
  }
};