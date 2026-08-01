# 27. Remove Element

## Labels

- Array
- Two Pointers

## Mastery

- Attempts: OOH
- Status: Familiar

## Link

https://leetcode.com/problems/remove-element/

## Problem Description

Remove all occurrences of a value in-place and return the remaining length.

## My Solution

```cpp
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    if (nums.empty()) {
      return 0;
    }

    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }

      fast++;
    }

    return slow;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
