# 912. Sort an Array - Radix Sort

## Labels

- Array
- Sorting

## Mastery

- Attempts: XX
- Status: Beginner

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `radix_sort.cpp`.

## Standard Answer

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    vector<int> negatives;
    vector<int> nonNegatives;

    for (int num : nums) {
      if (num < 0) {
        negatives.push_back(-num);
      } else {
        nonNegatives.push_back(num);
      }
    }

    radixSortNonNegative(negatives);
    radixSortNonNegative(nonNegatives);

    int index = 0;
    for (int i = static_cast<int>(negatives.size()) - 1; i >= 0; --i) {
      nums[index++] = -negatives[i];
    }
    for (int num : nonNegatives) {
      nums[index++] = num;
    }

    return nums;
  }

private:
  void radixSortNonNegative(vector<int> &nums) {
    if (nums.empty()) {
      return;
    }

    int maxValue = *max_element(nums.begin(), nums.end());
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
      countingSortByDigit(nums, exp);
    }
  }

  void countingSortByDigit(vector<int> &nums, int exp) {
    vector<int> output(nums.size());
    vector<int> count(10);

    for (int num : nums) {
      ++count[(num / exp) % 10];
    }

    for (int i = 1; i < 10; ++i) {
      count[i] += count[i - 1];
    }

    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
      int digit = (nums[i] / exp) % 10;
      output[--count[digit]] = nums[i];
    }

    nums = output;
  }
};
```

## Complexity

- Time: O(d * (n + b)), where `d` is digit count and `b` is the base
- Space: O(n + b)
