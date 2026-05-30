# Interview. Reverse Halves and Keep Middle

## Labels

- Linked List
- Two Pointers

## Mastery

- Attempts: OO
- Status: Proficient

## Link

Custom interview problem.

## Problem Description

Given the head of a singly linked list, reverse the left half and reverse the right half. If the list length is odd, keep the middle node in its original position between the two reversed halves.

The node values must not be changed; the list should be transformed by relinking nodes.

Examples:

```text
Input:  1 -> 2 -> 3 -> 4
Output: 2 -> 1 -> 4 -> 3
```

```text
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 2 -> 1 -> 3 -> 5 -> 4
```

```text
Input:  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
Output: 3 -> 2 -> 1 -> 4 -> 7 -> 6 -> 5
```

## My Solution

```cpp
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
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the linked list.
- Space: O(1), using only a constant number of pointers.
