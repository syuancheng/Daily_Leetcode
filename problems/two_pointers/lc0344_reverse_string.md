# 344. Reverse String

## Labels

- String
- Two Pointers

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/reverse-string/

## Problem Description

Given an array of characters, reverse it in place.

## My Solution

```cpp
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    if (s.empty()) {
      return;
    }

    size_t left = 0;
    size_t right = s.size() - 1;

    while (left < right) {
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      left++;
      right--;
    }
  }
};
```

## Complexity

- Time: O(n).
- Space: O(1).
