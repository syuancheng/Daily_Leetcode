# 3. Longest Substring Without Repeating Characters

## Labels

- Hash Table
- String
- Sliding Window

## Mastery

- Attempts: OO
- Status: Proficient

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/longest-substring-without-repeating-characters/

## Problem Description

Return the length of the longest substring without repeated characters.

## My Solution

```cpp
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>

/**
3. 无重复字符的最长子串
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0;

    while (right < s.size()) {
      char c = s[right];
      right++;

      window[c]++;

      while (window[c] > 1) {
        char d = s[left];
        left++;
        window[d]--;
      }

      if (right - left > res) {
        res = right - left;
      }
    }
    return res;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(min(n, charset)).
