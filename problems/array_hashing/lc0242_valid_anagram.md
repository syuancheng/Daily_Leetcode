# 242. Valid Anagram

## Labels

- Hash Table
- String
- Sorting

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/valid-anagram/

## Problem Description

Determine whether two strings are anagrams.

## My Solution

```cpp
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> nums(26, 0);
    for (auto &ch : s) {
      nums[ch - 'a']++;
    }

    for (auto &ch : t) {
      nums[ch - 'a']--;
      if (nums[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
