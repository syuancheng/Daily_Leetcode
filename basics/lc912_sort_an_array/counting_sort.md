# 912. Sort an Array - Counting Sort

## Labels

- Array
- Sorting
- Counting

## Mastery

- Attempts: XX
- Status: Beginner

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `counting_sort.cpp`.

## Standard Answer

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (nums.empty()) {
      return nums;
    }

    int minValue = *min_element(nums.begin(), nums.end());
    int maxValue = *max_element(nums.begin(), nums.end());
    vector<int> count(maxValue - minValue + 1);

    for (int num : nums) {
      ++count[num - minValue];
    }

    int index = 0;
    for (int i = 0; i < count.size(); ++i) {
      while (count[i] > 0) {
        nums[index++] = i + minValue;
        --count[i];
      }
    }

    return nums;
  }
};
```

## Complexity

- Time: O(n + k), where `k` is the value range
- Space: O(k)
