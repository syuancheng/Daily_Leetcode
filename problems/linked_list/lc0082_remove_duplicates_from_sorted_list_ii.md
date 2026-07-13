# 82. Remove Duplicates from Sorted List II

## Labels

- Linked List
- Two Pointers

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

## Problem Description

Given the head of a sorted linked list, delete all nodes that have duplicate values so only values that appear once remain.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy(0, head);
    ListNode *prev = &dummy;
    ListNode *cur = head;

    while (cur != nullptr) {
      bool duplicated = false;
      while (cur->next != nullptr && cur->val == cur->next->val) {
        duplicated = true;
        cur = cur->next;
      }

      if (duplicated) {
        prev->next = cur->next;
      } else {
        prev = prev->next;
      }
      cur = cur->next;
    }

    return dummy.next;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
