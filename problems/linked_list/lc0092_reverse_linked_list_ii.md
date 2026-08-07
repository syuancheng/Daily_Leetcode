# 92. Reverse Linked List II

## Labels

- Linked List

## Mastery

- Attempts: OOH
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/reverse-linked-list-ii/

## Problem Description

Reverse the nodes of a linked list from position left to right.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    if (left == right) {
      return head;
    }
    ListNode *dummy = new ListNode(0, head);
    auto pre = dummy, p = pre->next;
    ListNode *q;
    int i = 0;

    while (i < left - 1 && p != nullptr) {
      pre = p;
      p = p->next;
      i++;
    }

    while (i < right -1 && p != nullptr) {
      q = p->next;
      p = q->next;
      q->next = pre->next;
      pre->next = q;
      i++;
    }

    return dummy->next;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
