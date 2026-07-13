# 23. Merge k Sorted Lists

## Labels

- Linked List
- Heap
- Divide and Conquer

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/merge-k-sorted-lists/

## Problem Description

Given an array of sorted linked-list heads, merge all lists into one sorted linked list and return its head.

## My Solution

```cpp
#include "../common/nodes.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

    for (ListNode *head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }

    ListNode dummy(-1);
    ListNode *tail = &dummy;

    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();

      tail->next = node;
      tail = tail->next;
      if (node->next != nullptr) {
        pq.push(node->next);
      }
    }

    return dummy.next;
  }
};
```

## Complexity

- Time: O(n log k), where n is the total number of nodes and k is the number of lists.
- Space: O(k).
