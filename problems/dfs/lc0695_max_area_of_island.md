# 695. Max Area of Island

## Labels

- Array
- Matrix
- DFS

## Link

https://leetcode.com/problems/max-area-of-island/

## Problem Description

Given an `m x n` binary matrix `grid`, return the maximum area of an island in the grid.

An island is a group of `1`s connected horizontally or vertically. The area of an island is the number of cells with value `1` in that connected component.

If there is no island, return `0`.

Example:

```text
Input: grid = [[0,0,1,0,0,0,1,1]]
Output: 2
```

## Notes

- This is a DFS flood-fill style problem.
- Scan each cell. When a `1` is found, DFS through the connected island, count its area, mark visited cells, and update the maximum area.
- You can mark a visited land cell by changing it from `1` to `0`.
