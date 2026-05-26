# 27. Remove Element

## Labels

- Array
- Two Pointers

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/remove-element/

## Problem Description

Remove all occurrences of a value in-place and return the remaining length.

## My Solution

```cpp
#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val) {
  int slow = 0;
  for (int fast = 0; fast < nums.size(); fast++) {
    if (nums[fast != val]) {
      nums[slow++] = nums[fast];
    }
  }
  return slow;
}

int removeElementv2(std::vector<int> &nums, int val) {
  nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
  return nums.size();
}
```

## Complexity

- Time: O(n).
- Space: O(1).
