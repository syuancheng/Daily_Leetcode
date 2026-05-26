# 328. Odd Even Linked List

## Labels

- Linked List

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/odd-even-linked-list/

## Problem Description

Group odd-indexed nodes followed by even-indexed nodes.

## My Solution

```cpp
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *h = new ListNode(0);

    ListNode *r = h, *pre = head, *ou = head->next, *tail, *q;

    while (ou != nullptr) {
      q = ou->next;
      if (q == nullptr) {
        tail = pre;
        r->next = ou;
        r = r->next;
        pre->next = nullptr;
        break;
      }
      r->next = ou;
      r = r->next;
      ou->next = nullptr;

      pre->next = q;

      ou = q->next;
      pre = q;
      tail = q;
    }

    tail->next = h->next;

    return head;
  }

  ListNode *oddEvenList2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *p = head, *q, *r, *tail;

    ListNode *h = new ListNode(0);

    r = h;

    while (p != nullptr) {
      tail = p;
      q = p->next;
      if (q != nullptr) {
        p->next = q->next;
        r->next = q;
        r = q;
        p = p->next;
      } else {
        break;
      }
    }

    r->next = nullptr;
    tail->next = h->next;

    return head;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
