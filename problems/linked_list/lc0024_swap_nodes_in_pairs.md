# 24. Swap Nodes in Pairs

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

https://leetcode.com/problems/swap-nodes-in-pairs/

## Problem Description

Swap every two adjacent nodes in a linked list and return the new head.

## My Solution

```cpp
#include "../common/nodes.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *h = new ListNode(0, head);

    ListNode *r = h, *p = head, *q;

    while (p != nullptr) {
      q = p->next;
      if (q != nullptr) {
        p->next = q->next;
        q->next = p;
        r->next = q;
        r = p;
        p = p->next;
      } else {
        break;
      }
    }

    return h->next;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
