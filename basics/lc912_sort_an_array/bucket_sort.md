# 912. Sort an Array - Bucket Sort

## Labels

- Array
- Sorting

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `bucket_sort.cpp`.

## Standard Answer

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums;
    }

    int minValue = *min_element(nums.begin(), nums.end());
    int maxValue = *max_element(nums.begin(), nums.end());
    int bucketSize = 100;
    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    for (int num : nums) {
      int index = (num - minValue) / bucketSize;
      buckets[index].push_back(num);
    }

    int write = 0;
    for (vector<int> &bucket : buckets) {
      insertionSort(bucket);
      for (int num : bucket) {
        nums[write++] = num;
      }
    }

    return nums;
  }

private:
  void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      int current = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > current) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = current;
    }
  }
};
```

## Complexity

- Time: O(n + m^2) in the worst bucket distribution, where `m` is the largest bucket size
- Space: O(n + bucket count)
