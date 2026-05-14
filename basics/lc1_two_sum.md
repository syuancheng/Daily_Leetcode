# 1. Two Sum

## Labels

- Array
- Hash Table

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/two-sum/

## Problem Description

Given an integer array `nums` and an integer `target`, return the indices of two different elements whose values add up to `target`.

The input is guaranteed to have exactly one valid answer, and the same array element cannot be used twice. The answer can be returned in any order.

Key constraints:

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Exactly one valid answer exists.

Example:

```text
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

## My Solution

```cpp
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map; // num->index

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (const auto &iter = map.find(target - num); iter != map.end()) {
        return {iter->second, i};
      }
      map.insert(std::make_pair(num, i));
    }

    return {};
  }
};
```

## Complexity

- Time: O(n), where `n` is the length of `nums`.
- Space: O(n), because the hash map may store up to `n` values in the worst case.
