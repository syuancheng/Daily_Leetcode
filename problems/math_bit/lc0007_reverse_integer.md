# 7. Reverse Integer

## Labels

- Math

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

https://leetcode.com/problems/reverse-integer/

## Problem Description

Reverse the digits of a signed 32-bit integer, returning 0 on overflow.

## My Solution

```cpp
#include <climits>
#include <iostream>

int reverse(int x) {
  long ans = 0;
  long y = x;

  int d, flag;
  flag = (x < 0 ? -1 : 1);

  if (x < 0) {
    y = -y;
  }
  // 321
  while (y != 0) {
    d = y % 10;
    y = y / 10;

    ans = ans * 10 + d;
  }
  ans = flag * ans;

  if (ans < INT_MIN || ans > INT_MAX) {
    return 0;
  }
  return ans;
}

int main() {
  int ret = reverse(312);

  std::cout << "result: " << ret << std::endl;

  return 0;
}
```

## Complexity

- Time: O(log n).
- Space: O(1).
