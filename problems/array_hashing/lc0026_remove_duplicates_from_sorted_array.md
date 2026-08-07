# 26. Remove Duplicates from Sorted Array

## Labels

- Array
- Two Pointers

## Mastery

- Attempts: OOHH
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

## Problem Description

Remove duplicates from a sorted array in-place and return the number of unique elements.

## My Solution

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[slow] != nums[fast]) {
        slow++;
        nums[slow] = nums[fast];
      }
      fast++;
    }

    return slow + 1;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
