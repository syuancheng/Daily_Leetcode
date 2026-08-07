# 567. Permutation in String

## Labels

- Hash Table
- String
- Sliding Window

## Mastery

- Attempts: OOH
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/permutation-in-string/

## Problem Description

Determine whether s2 contains a permutation of s1.

## My Solution

```cpp
#include <string>
#include <vector>

using namespace std;

/**
567. 字符串的排列
*/

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char c : s1) {
      need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;

    while (right < s2.size()) {
      char c = s2[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }

      while (right - left >= s1.size()) {
        if (valid == need.size()) {
          return true;
        }

        char d = s2[left];
        left++;
        if (need.count(d)) {
          if (need[d] == window[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return false;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
