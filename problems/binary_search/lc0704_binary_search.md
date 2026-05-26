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
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] < target) {
        l = mid+1;
      } else {
        r = mid -1;
      }
    }
    return -1;
  }
};
```

## Complexity

- Time: O(log n).
- Space: O(1).
