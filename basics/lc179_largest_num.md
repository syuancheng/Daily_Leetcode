# 179. Largest Number

## Labels

- Array
- Sorting
- String

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/largest-number/

## Problem Description

Given a list of non-negative integers, arrange them so that they form the largest possible number and return it as a string.

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

- Time: O(n log n * k), where `k` is the average number of digits used in string comparisons.
- Space: O(n * k), mainly for generated strings and the result.
