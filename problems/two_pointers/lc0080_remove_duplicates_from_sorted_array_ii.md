# 80. Remove Duplicates from Sorted Array II

## Labels

- Array
- Two Pointers

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

## Problem Description

Keep at most two occurrences of each value in a sorted array in-place.

## My Solution

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if (n <= 2) {
        return nums.size();
      }

      int fast = 2, slow = 2;
      while (fast < n) {
        if (nums[fast] != nums[slow-2]) {
          nums[slow] = nums[fast];
          ++slow;
        }
        ++fast;
      }

      return slow;
    }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
