# 237. Delete Node in a Linked List

## Labels

- Linked List

## Mastery

- Attempts: OO
- Status: Proficient

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/delete-node-in-a-linked-list/

## Problem Description

Delete a non-tail node from a singly linked list when only that node is given.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  void deleteNode(ListNode *node) {
    if (!node->next) {
      return;
    }
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
```

## Complexity

- Time: O(1).
- Space: O(1).
