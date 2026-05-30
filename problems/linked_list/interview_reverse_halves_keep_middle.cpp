#include "list_node.h"

ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *curr = head;

  while (curr != nullptr) {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

ListNode *reverseHalvesKeepMiddle(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  int length = 0;
  for (ListNode *node = head; node != nullptr; node = node->next) {
    ++length;
  }

  int leftLength = length / 2;
  ListNode *left = head;
  ListNode *prev = nullptr;
  ListNode *curr = head;

  for (int i = 0; i < leftLength; ++i) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = nullptr;

  ListNode *middle = nullptr;
  ListNode *right = curr;
  if (length % 2 == 1) {
    middle = curr;
    right = curr->next;
    middle->next = nullptr;
  }

  ListNode *newHead = reverseList(left);
  ListNode *newRight = reverseList(right);

  ListNode *tail = newHead;
  while (tail->next != nullptr) {
    tail = tail->next;
  }

  if (middle != nullptr) {
    tail->next = middle;
    tail = middle;
  }
  tail->next = newRight;

  return newHead;
}
