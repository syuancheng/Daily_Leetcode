#include "../../problems/common/nodes.h"

class ReverseFirstNListNodesIterative {
public:
  ListNode *reverseN(ListNode *head, int n) {
    ListNode *prev = nullptr;
    ListNode *cur = head;

    while (cur != nullptr && n > 0) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      n--;
    }
    if (head != nullptr) {
      head->next = cur;
    }

    return prev;
  }
};

class ReverseFirstNListNodesRecursive {
private:
  ListNode *successor = nullptr;

public:
  ListNode *reverseN(ListNode *head, int n) {
    if (head == nullptr || n <= 1) {
      successor = head == nullptr ? nullptr : head->next;
      return head;
    }

    ListNode *last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = successor;

    return last;
  }
};
