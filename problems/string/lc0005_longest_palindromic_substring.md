# 5. Longest Palindromic Substring

## Labels

- String
- Two Pointers

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/longest-palindromic-substring/

## Problem Description

Given a string, return the longest substring that is a palindrome.

## My Solution

```cpp
#include <cstddef>
#include <string>

using namespace std;

class Solution {
private:
  string palindrome(const string &s, int left, int right) {
    while (left >= 0 && right < static_cast<int>(s.size()) &&
           s[static_cast<size_t>(left)] == s[static_cast<size_t>(right)]) {
      left--;
      right++;
    }

    return s.substr(static_cast<size_t>(left + 1),
                    static_cast<size_t>(right - left - 1));
  }

public:
  string longestPalindrome(string s) {
    string result;

    for (int i = 0; i < static_cast<int>(s.size()); i++) {
      string odd = palindrome(s, i, i);
      string even = palindrome(s, i, i + 1);

      result = result.size() > odd.size() ? result : odd;
      result = result.size() > even.size() ? result : even;
    }

    return result;
  }
};
```

## Complexity

- Time: O(n^2).
- Space: O(n), because each expansion returns a substring.
