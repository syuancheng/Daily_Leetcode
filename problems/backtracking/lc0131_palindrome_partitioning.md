# 131. Palindrome Partitioning

## Labels

- String
- Backtracking
- DFS

## Mastery

- Attempts: X
- Status: Beginner

## Link

https://leetcode.com/problems/palindrome-partitioning/

## Problem Description

Given a string `s`, partition `s` so that every substring in the partition is a palindrome.

Return all possible palindrome partitioning results.

Example:

```text
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

## My Solution

```cpp
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<string>> result;

public:
  bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
  void dfs(string &s, int start, vector<string> &path) {
    if (s.size() == start) {
      result.push_back(path);
      return;
    }
    for (int len = 1; start + len <= s.size(); len++) {
      string sub = s.substr(start, len);
      if (isPalindrome(sub)) {
        path.push_back(sub);
        dfs(s, start + len, path);
        path.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<string> data;
    dfs(s, 0, data);
    return result;
  }
};
```

## Complexity

- Time: O(n * 2^n), where `n` is the length of `s`; there can be exponentially many partitions, and substring/palindrome checks add linear work.
- Space: O(n) auxiliary space for the recursion path, excluding the output.
