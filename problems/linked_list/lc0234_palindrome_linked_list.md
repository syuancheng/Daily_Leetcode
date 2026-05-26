# 234. Palindrome Linked List

## Labels

- Linked List
- Two Pointers
- Stack

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/palindrome-linked-list/

## Problem Description

Determine whether a linked list is a palindrome.

## My Solution

```cpp
#include "list_node.h"
#include <cstddef>
#include <vector>

/**
234. 回文链表
*/
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }
    std::vector<int> vals;

    ListNode *curr = head;
    while (curr) {
      vals.push_back(curr->val);
      curr = curr->next;
    }

    int l = 0, r = vals.size() - 1;
    while (l < r) {
      if (vals[l] != vals[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }

  ListNode *reverseListNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *dummy = new ListNode(0);

    ListNode *curr = head;
    while (curr) {
      ListNode *tmp = curr->next;
      curr->next = dummy->next;
      dummy->next = curr;

      curr = tmp;
    }
    return dummy->next;
  }

  bool isPalindrome2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *head2 = reverseListNode(slow->next);
    ListNode *head1 = head;
    while (head1 && head2) {
      if (head1->val != head2->val) {
        return false;
      }
      head1 = head1->next;
      head2 = head2->next;
    }

    return true;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
