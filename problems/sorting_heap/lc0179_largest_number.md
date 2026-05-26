# 179. Largest Number

## Labels

- Array
- String
- Sorting
- Greedy

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/largest-number/

## Problem Description

Arrange non-negative integers to form the largest possible number.

## My Solution

```cpp
#include <algorithm>
#include <vector>
#include <string>

using namespace std;




class Solution {
public:
    string largestNumber(vector<int>& nums) {
      stable_sort(nums.begin(), nums.end(), [](const int &l, const int &r) {
        return to_string(l) + to_string(r) > to_string(r) + to_string(l);
      });
      if (nums[0] == 0) {
        return "0";
      }
      string ret;
      for (int& n : nums) {
        ret += to_string(n);
      }

      return ret;
    }
};
```

## Complexity

- Time: O(n log n * k).
- Space: O(nk).
