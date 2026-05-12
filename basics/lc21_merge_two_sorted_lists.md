# 21. Merge Two Sorted Lists

## Labels

- Linked List
- Recursion

## Link

https://leetcode.com/problems/merge-two-sorted-lists/

## Problem Description

Given the heads of two sorted linked lists, merge them into one sorted linked list by splicing together the existing nodes. Return the head of the merged list.

## My Solution

```cpp
#include "type.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *head1 = list1, *head2 = list2;

    ListNode *pre = dummy;

    while (head1 != nullptr && head2 != nullptr) {
      if (head1->val <= head2->val) {
        pre->next = head1;

        head1 = head1->next;
      } else {
        pre->next = head2;
        head2 = head2->next;
      }
      pre = pre->next;
    }

    if (head1 != nullptr) {
      pre->next = head1;
    } else if (head2 != nullptr) {
      pre->next = head2;
    }

    return dummy->next;
  }

  ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2) {
    // 找终点
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists2(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists2(list1, list2->next);
      return list2;
    }
  }
};
```

## Complexity

- Time: O(m + n), where `m` and `n` are the lengths of the two lists.
- Space: O(1) for the iterative solution, or O(m + n) recursion stack for the recursive solution.
