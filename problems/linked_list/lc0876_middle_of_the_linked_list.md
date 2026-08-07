# 876. Middle of the Linked List

## Labels

- Linked List
- Two Pointers

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

https://leetcode.com/problems/middle-of-the-linked-list/

## Problem Description

Return the middle node of a linked list.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    int count = 0;

    auto *tmp = head;
    while (tmp != nullptr) {
      count++;
      tmp = tmp->next;
    }

    int midIdx = count / 2 + 1;

    ListNode *h = new ListNode(0, head);

    auto *pre = h, *p = head;

    int i = 1;
    while (p != nullptr) {
      if (i == midIdx) {
        break;
      } else {
        pre = p;
        p = p->next;
      }
      i++;
    }

    return p;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
