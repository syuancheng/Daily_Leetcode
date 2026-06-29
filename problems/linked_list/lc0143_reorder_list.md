# 143. Reorder List

## Labels

- Linked List
- Two Pointers
- Recursion

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/reorder-list/

## Problem Description

Given the head of a singly linked list, reorder the list from:

```text
L0 -> L1 -> ... -> Ln-1 -> Ln
```

to:

```text
L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
```

The node values must not be changed; the list must be reordered by relinking the existing nodes.

Example:

```text
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

## My Solution

```cpp
#include "../common/nodes.h"

/**
143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
*/

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next) {
      return;
    }
    ListNode *mid = getMiddleNode(head);
    ListNode *l1 = head;
    ListNode *l2 = reverseList(mid->next);
    mid->next = nullptr;

    ListNode *l1_tmp, *l2_tmp;

    while (l1 && l2) {//这个合并的前提是l1.size > l2.size
      l1_tmp = l1->next;
      l2_tmp = l2->next;

      l1->next = l2;
      l2->next = l1_tmp;
      l1 = l1_tmp;
      l2 = l2_tmp;
    }
  }

  ListNode *getMiddleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *dummy = new ListNode();

    ListNode *tmp;
    while (head) {
      tmp = head->next;

      head->next = dummy->next;
      dummy->next = head;

      head = tmp;
    }
    return dummy->next;
  }
};
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the linked list.
- Space: O(1), excluding the constant number of pointer variables used by the algorithm.
