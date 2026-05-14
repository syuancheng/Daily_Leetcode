# 704. Binary Search

## Labels

- Array
- Binary Search

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/binary-search/

## Problem Description

Given a sorted integer array `nums` and an integer `target`, return the index of `target` if it exists. Otherwise, return `-1`.

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

- Time: O(log n), where `n` is the length of `nums`.
- Space: O(1).
