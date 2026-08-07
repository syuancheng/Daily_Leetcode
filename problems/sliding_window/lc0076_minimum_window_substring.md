# 76. Minimum Window Substring

## Labels

- Hash Table
- String
- Sliding Window

## Mastery

- Attempts: OOHHO
- Status: Proficient

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/minimum-window-substring/

## Problem Description

Find the smallest substring of s containing all characters of t.

## My Solution

```cpp
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) {
      need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;

    int start = 0, len = INT_MAX;

    while (right < s.size()) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }

      while (valid == need.size()) {
        if (right - left < len) {
          start = left;
          len = right - left;
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

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
```

## Complexity

- Time: O(m + n).
- Space: O(k).
