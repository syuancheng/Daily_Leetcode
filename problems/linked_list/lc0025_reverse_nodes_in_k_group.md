# 25. Reverse Nodes in k-Group

## Labels

- Linked List
- Recursion

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/reverse-nodes-in-k-group/

## Problem Description

Given a linked list, reverse every consecutive group of k nodes. Nodes in a final group smaller than k stay in their original order.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
private:
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
    head->next = cur;

    return prev;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *tail = head;
    for (int i = 0; i < k; i++) {
      if (tail == nullptr) {
        return head;
      }
      tail = tail->next;
    }

    ListNode *newHead = reverseN(head, k);
    head->next = reverseKGroup(tail, k);
    return newHead;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(n/k) recursion depth.
