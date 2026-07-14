# 303. Range Sum Query - Immutable

## Labels

- Array
- Design
- Prefix Sum

## Mastery

- Attempts: O
- Status: Familiar

## Link

https://leetcode.com/problems/range-sum-query-immutable/

## Problem Description

Preprocess an integer array so that the sum of any inclusive range `[left, right]`
can be queried repeatedly.

## My Solution

Store one extra leading zero in `prefix_sums_`, where `prefix_sums_[i]` is the
sum of elements before index `i`. Then the inclusive range sum is:

```cpp
prefix_sums_[right + 1] - prefix_sums_[left]
```

```cpp
#include <cstddef>
#include <vector>

using namespace std;

class NumArray {
  vector<int> prefix_sums_;

public:
  NumArray(vector<int> &nums) : prefix_sums_(nums.size() + 1, 0) {
    for (size_t i = 0; i < nums.size(); ++i) {
      prefix_sums_[i + 1] = prefix_sums_[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return prefix_sums_[static_cast<size_t>(right) + 1] -
           prefix_sums_[static_cast<size_t>(left)];
  }
};
```

## Complexity

- Time: O(n) construction, O(1) per query.
- Space: O(n).
