# 967. Numbers With Same Consecutive Differences

## Labels

- Backtracking
- DFS

## Mastery

- Attempts: HO
- Status: Proficient

## Link

https://leetcode.com/problems/numbers-with-same-consecutive-differences/

## Problem Description

Return all non-negative integers of length `n` where the absolute difference
between every two consecutive digits is `k`.

## My Solution

Build the number digit by digit. From the last digit, the only possible next
digits are `last + k` and `last - k`. Start with `1` through `9` for multi-digit
numbers to avoid leading zeroes; when `n == 1`, `0` is also valid.

## Complexity

- Time: O(2^n), with pruning by digit bounds
- Space: O(n) recursion depth, excluding output
