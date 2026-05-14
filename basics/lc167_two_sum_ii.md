# 167. Two Sum II - Input Array Is Sorted

## Labels

- Array
- Hash Table
- Two Pointers

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

## Problem Description

Given a 1-indexed sorted integer array `numbers` and an integer `target`, return the indices of two numbers whose sum is `target`. The answer is guaranteed to exist, and each input has exactly one solution.

## My Solution

```cpp
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> map; // num -> index

    for (int i = 0; i < numbers.size(); i++) {
      int another = target - numbers[i];
      if (const auto &iter = map.find(another); iter != map.end()) {
        return {iter->second, i + 1};
      }
      map[numbers[i]] = i + 1;
    }
    return {};
  }
};
```

## Complexity

- Time: O(n), where `n` is the length of `numbers`.
- Space: O(n), because the hash map stores previously seen values.
