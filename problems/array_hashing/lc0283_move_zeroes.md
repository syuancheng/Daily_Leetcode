# 283. Move Zeroes

## Labels

- Array
- Two Pointers

## Mastery

- Attempts: OOHO
- Status: Proficient

## Link

https://leetcode.com/problems/move-zeroes/

## Problem Description

Move all zeroes to the end while maintaining non-zero order.

## My Solution

```cpp
#include <vector>

using namespace std;

//[0,0,1,0,3,12]
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i = removeElement(nums, 0);

    while (i < nums.size()) {
      nums[i++] = 0;
    }
  }

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
