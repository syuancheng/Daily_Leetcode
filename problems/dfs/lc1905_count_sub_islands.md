# 1905. Count Sub Islands

## Labels

- Array
- Matrix
- DFS

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

https://leetcode.com/problems/count-sub-islands/

## Problem Description

Given two binary grids, count the islands in `grid2` whose every land cell is
also land in `grid1`.

## My Solution

DFS each island in `grid2`. While sinking the whole island, keep a boolean that
records whether every visited cell is also land in `grid1`.

The key detail is not to return immediately when one bad cell is found. The
whole `grid2` island still has to be marked visited, otherwise a later cell from
the same invalid island may be counted again.

## Complexity

- Time: O(mn)
- Space: O(mn) worst-case recursion stack
