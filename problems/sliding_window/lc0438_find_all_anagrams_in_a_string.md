# 438. Find All Anagrams in a String

## Labels

- Hash Table
- String
- Sliding Window

## Mastery

- Attempts: OOO
- Status: Proficient

## Link

https://leetcode.com/problems/find-all-anagrams-in-a-string/

## Problem Description

Return all start indices of p anagrams in s.

## My Solution

```cpp
#include <string>
#include <unordered_set>
#include <vector>

/**
438. 找到字符串中所有字母异位词
*/

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    unordered_map<char, int> need, window;
    for (char c : p) {
      need[c]++;
    }

    int left = 0, right = 0, valid = 0;

    while (right < s.size()) {
      char c = s[right];
      right++;
      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          valid++;
        }
      }

      while (right - left >= p.size()) {
        if (valid == need.size()) {
          res.push_back(left);
        }
        char d = s[left];
        left++;

        if (need.count(d)) {
          if (need[d] == window[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return res;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
