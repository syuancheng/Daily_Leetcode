# 203. Remove Linked List Elements

## Labels

- Linked List
- Recursion

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/remove-linked-list-elements/

## Problem Description

Remove all nodes with a given value from a linked list.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *node = new ListNode(0, head);

    auto prev = node;

    while (prev) {
      auto cur = prev->next;
      if (!cur) {
        break;
      }
      if (cur->val != val) {
        cur = cur->next;
        prev = prev->next;
        continue;
      }
      prev->next = cur->next;
      cur->next = nullptr;
    }

    return node->next;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
