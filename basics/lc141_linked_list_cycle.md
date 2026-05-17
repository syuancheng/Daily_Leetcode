# 141. Linked List Cycle

## Labels

- Linked List
- Two Pointers

## Mastery

- Attempts: XO
- Status: Proficient

## Link

https://leetcode.com/problems/linked-list-cycle/

## Problem Description

Given the head of a linked list, determine whether the list contains a cycle.

## My Solution

```cpp
#include "type.h"

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
```

## Complexity

- Time: O(n), where `n` is the number of nodes.
- Space: O(1).
