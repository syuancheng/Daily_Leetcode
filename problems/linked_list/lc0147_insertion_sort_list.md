# 147. Insertion Sort List

## Labels

- Linked List
- Sorting

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

https://leetcode.com/problems/insertion-sort-list/

## Problem Description

Sort a linked list using insertion sort.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *h = new ListNode(0, head);
    ListNode *p = h->next->next;
    h->next->next = nullptr;

    ListNode *q, *pre;
    while (p != nullptr) {
      q = p->next;
      pre = h;
      while (pre->next != nullptr && pre->next->val < p->val) {
        pre = pre->next;
      }
      p->next = pre->next;
      pre->next = p;

      p = q;
    }

    return h->next;
  }
};
```

## Complexity

- Time: O(n^2).
- Space: O(1).
