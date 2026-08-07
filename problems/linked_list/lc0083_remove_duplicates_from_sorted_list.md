# 83. Remove Duplicates from Sorted List

## Labels

- Linked List
- Two Pointers

## Mastery

- Attempts: H
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/remove-duplicates-from-sorted-list/

## Problem Description

Given the head of a sorted linked list, delete duplicate nodes so each value appears once.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    ListNode *slow = head, *fast = head;

    while (fast != nullptr) {
      if (fast->val != slow->val) {
        slow->next = fast;
        slow = slow->next;
      }
      fast = fast->next;
    }

    slow->next = nullptr;

    return head;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
