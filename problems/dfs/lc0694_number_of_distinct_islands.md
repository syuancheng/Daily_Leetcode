# 694. Number of Distinct Islands

## Labels

- Array
- Matrix
- DFS
- Hash Table

## Mastery

- Attempts: HO
- Status: Proficient

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/number-of-distinct-islands/

## Problem Description

Count how many different island shapes appear in the grid. Two islands are the
same if one can be translated to the other without rotation or reflection.

## My Solution

Serialize each island's DFS walk. Append the direction when entering a cell and
append the negative direction when leaving it, so different branch structures do
not collapse to the same string.

## Complexity

- Time: O(mn)
- Space: O(mn)
