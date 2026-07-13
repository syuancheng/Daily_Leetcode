# 19. Remove Nth Node From End of List

## Labels

- Linked List
- Two Pointers

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

## Problem Description

Given the head of a linked list, remove the nth node from the end and return the new head.

## My Solution

```cpp
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
```

## Complexity

- Time: O(n).
- Space: O(1).
