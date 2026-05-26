# 237. Delete Node in a Linked List

## Labels

- Linked List

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/delete-node-in-a-linked-list/

## Problem Description

Delete a non-tail node from a singly linked list when only that node is given.

## My Solution

```cpp

struct ListNode {
  int val;

  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int n) : val(n), next(nullptr) {}
};

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
