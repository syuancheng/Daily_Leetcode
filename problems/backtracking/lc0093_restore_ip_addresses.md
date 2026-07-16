# 93. Restore IP Addresses

## Labels

- String
- Backtracking
- DFS

## Mastery

- Attempts: HH
- Status: Beginner

## Link

https://leetcode.com/problems/restore-ip-addresses/

## Problem Description

Given a string `s` containing only digits, return all possible valid IPv4 addresses that can be formed by inserting three dots into `s`.

A valid IPv4 address has exactly four decimal parts. Each part must be between `0` and `255`, inclusive, and must not contain leading zeroes unless the part is exactly `"0"`.

Examples:

```text
Input: s = "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
```

```text
Input: s = "0000"
Output: ["0.0.0.0"]
```

```text
Input: s = "101023"
Output: ["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]
```

## My Solution

```cpp
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> result;

public:
  bool isValid(string &s) {
    if (s.empty()) {
      return false;
    }
    if (s.size() > 1 && s.front() == '0') {
      return false;
    }

    int num = 0;
    for (char c : s) {
      num = num * 10 + (c - '0');
      if (num > 255) {
        return false;
      }
    }
    return true;
  }

  void dfs(string &s, int start, vector<string> &path) {
    if (path.size() == 4) {
      if (start == s.size()) {
        string ip = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
        result.push_back(ip);
      }
    }

    for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
      string sub = s.substr(start, len);
      if (isValid(sub)) {
        path.push_back(sub);
        dfs(s, start + len, path);
        path.pop_back();
      }
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> path;
    dfs(s, 0, path);
    return result;
  }
};
```

## Complexity

- Time: O(1) with respect to input length, because an IPv4 address can have at most 12 digits and each segment has at most 3 digits. More generally, the DFS tries at most 3 choices for each of 4 segments.
- Space: O(1) auxiliary space, excluding the output, because the recursion depth is bounded by 4.
