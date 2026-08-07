# 20. Valid Parentheses

## Labels

- String
- Stack

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

https://leetcode.com/problems/valid-parentheses/

## Problem Description

Determine whether brackets in a string are valid and properly nested.

## My Solution

```cpp
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> sk;
    for (char &c : s) {
      if (c == ')' && !sk.empty()) {
        if (sk.top() != '(') {
          return false;
        }
        sk.pop();
      } else if (c == ']' && !sk.empty()) {
        if (sk.top() != '[') {
          return false;
        }
        sk.pop();
      } else if (c == '}' && !sk.empty()) {
        if (sk.top() != '{') {
          return false;
        }
        sk.pop();
      } else {
        sk.push(c);
      }
    }

    if (!sk.empty()) {
      return false;
    }
    return true;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(n).
