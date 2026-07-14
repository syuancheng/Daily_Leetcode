# 704. Binary Search

## Labels

- Array
- Binary Search

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/binary-search/

## Problem Description

Search a target in a sorted array and return its index, or -1.

## My Solution

```cpp
#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
      const int mid = left + (right - left) / 2;
      const size_t index = static_cast<size_t>(mid);
      if (nums[index] == target) {
        return mid;
      }

      if (nums[index] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};
```

## Complexity

- Time: O(log n).
- Space: O(1).
