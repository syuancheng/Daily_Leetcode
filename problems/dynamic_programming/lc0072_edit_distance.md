# 72. Edit Distance

## Labels

- String
- Dynamic Programming

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/edit-distance/

## Problem Description

Given two words, return the minimum number of insert, delete, and replace operations needed to convert the first word into the second word.

## My Solution

```cpp
#include <algorithm>
#include <cstddef>
#include <string>

using namespace std;

class Solution {
private:
  string a;
  string b;

  int dfs(int i, int j) {
    if (i == 0) {
      return j;
    }
    if (j == 0) {
      return i;
    }
    if (a[static_cast<size_t>(i - 1)] == b[static_cast<size_t>(j - 1)]) {
      return dfs(i - 1, j - 1);
    }

    int insertOp = dfs(i, j - 1) + 1;
    int deleteOp = dfs(i - 1, j) + 1;
    int replaceOp = dfs(i - 1, j - 1) + 1;

    return min({insertOp, deleteOp, replaceOp});
  }

public:
  int minDistance(string word1, string word2) {
    a = word1;
    b = word2;

    return dfs(static_cast<int>(a.size()), static_cast<int>(b.size()));
  }
};
```

## Complexity

- Time: O(3^(m+n)).
- Space: O(m+n).
