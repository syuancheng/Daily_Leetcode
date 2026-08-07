# 382. Linked List Random Node

## Labels

- Linked List
- Reservoir Sampling
- Randomized

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

https://leetcode.com/problems/linked-list-random-node/

## Problem Description

Return a random node value from a linked list with equal probability.

## My Solution

```cpp
#include <cstddef>
#include <cstdlib>
#include <random>
#include <vector>
#include "../common/nodes.h"

/**
382. 链表随机节点

*/
class Solution {
private:
  ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
      int ans = 0, count = 1;

      ListNode* node = head;
      while (node) {
        if (rand() % count == 0) {
          ans = node->val;
        }
        count++;
        node = node->next;
      }
      return ans;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

## Complexity

- Time: O(n) per getRandom.
- Space: O(1).
