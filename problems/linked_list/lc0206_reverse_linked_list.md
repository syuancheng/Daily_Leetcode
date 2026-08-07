# 206. Reverse Linked List

## Labels

- Linked List
- Recursion

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

https://leetcode.com/problems/reverse-linked-list/

## Problem Description

Reverse a singly linked list.

## My Solution

```cpp
#include "../common/nodes.h"

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

- Time: O(n).
- Space: O(1).
