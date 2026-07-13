# 167. Two Sum II - Input Array Is Sorted

## Labels

- Array
- Two Pointers
- Binary Search

## Mastery

- Attempts: OOH
- Status: Familiar

## Link

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

## Problem Description

Return 1-indexed positions of two numbers in a sorted array that add to target.

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

- Time: O(n).
- Space: O(1).
