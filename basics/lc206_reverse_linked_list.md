# 206. Reverse Linked List

## Labels

- Linked List

## Link

https://leetcode.com/problems/reverse-linked-list/

## Problem Description

Given the head of a singly linked list, reverse the list and return the new head.

## My Solution

```cpp
#include "type.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *dummy = new ListNode();
    ListNode *curr = head;
    while (curr) {
      ListNode *tmp = curr->next;

      curr->next = dummy->next;
      dummy->next = curr;

      curr = tmp;
    }
    return dummy->next;
  }
};
```

## Complexity

- Time: O(n), where `n` is the number of nodes.
- Space: O(1).
