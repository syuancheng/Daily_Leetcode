# 92. Reverse Linked List II

## Labels

- Linked List

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/reverse-linked-list-ii/

## Problem Description

Reverse the nodes of a linked list from position left to right.

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
