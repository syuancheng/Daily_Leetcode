# Interview. Implement atof

## Labels

- String
- Parsing
- Math

## Mastery

- Attempts: OO
- Status: Proficient

## Link

Custom interview problem.

## Problem Description

Implement a function similar to `atof` that converts a decimal string into a `double`.

For this simple interview version:

- The input contains only digits and at most one decimal point.
- Parse digits before and after the decimal point.
- Return the numeric value as a `double`.

Example:

```text
Input: "3.14"
Output: 3.14
```

## My Solution

```cpp
#include <climits>
#include <iomanip>
#include <iostream>
#include <string>

double myAtof(const std::string &s) {
  if (s.empty()) {
    return 0.0;
  }

  int dotIdx = INT_MAX;
  double result = 0.0;
  double factor = 0.1;

  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];

    if (c == '.') {
      dotIdx = i;
      continue;
    }

    if (i < dotIdx) {
      result = result * 10 + (c - '0');
    } else {
      result += (c - '0') * factor;
      factor *= 0.1;
    }
  }

  return result;
}

int main() {
  std::string s = "3.14001312";
  double res = myAtof(s);

  std::cout << std::setprecision(10) << res << std::endl;
}
```

## Approach

Use `dotIdx` to record whether the decimal point has appeared.

- Before seeing `.`, every digit belongs to the integer part, so update `result = result * 10 + digit`.
- After seeing `.`, every digit belongs to the fractional part. Start with `factor = 0.1`, add `digit * factor`, then multiply `factor` by `0.1`.

For example, `"3.14001312"` is parsed as:

```text
3 + 1 * 0.1 + 4 * 0.01 + 0 * 0.001 + 0 * 0.0001
  + 1 * 0.00001 + 3 * 0.000001 + 1 * 0.0000001 + 2 * 0.00000001
```

One detail: `std::cout` prints only 6 significant digits by default. If the parsed value looks shorter than expected, use `std::setprecision`, for example:

```cpp
std::cout << std::setprecision(10) << res << std::endl;
```

## Complexity

- Time: O(n), where `n` is the length of the input string.
- Space: O(1), using only a constant number of variables.
