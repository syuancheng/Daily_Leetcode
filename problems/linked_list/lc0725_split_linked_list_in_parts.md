# 725. Split Linked List in Parts

## Labels

- Linked List

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/split-linked-list-in-parts/

## Problem Description

Split a linked list into k consecutive parts as evenly as possible.

## My Solution

```cpp
#include <cstddef>
#include <vector>

using namespace std;
#include "../common/nodes.h"

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return {head};
    }

    int n = 0;
    ListNode *curr = head;
    while (curr) {
      n++;
      curr = curr->next;
    }

    int size = n / k, restSize = n % k;

    vector<ListNode *> ans =
        {}; // ans.size = k, [0, restSize-1]: size+1, [restSize, k-1]: size

    ListNode *h = new ListNode(0);

    

    return {};
  }
};
```

## Complexity

- Time: O(n + k).
- Space: O(k).
