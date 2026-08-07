# 773. Sliding Puzzle

## Labels

- BFS
- Matrix
- String

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

https://leetcode.com/problems/sliding-puzzle/

## Problem Description

Given a 2 x 3 board, return the minimum number of moves to reach
`[[1,2,3],[4,5,0]]`. The `0` tile can swap with an adjacent tile.

## My Solution

Flatten the board into a six-character string. Each string is a graph node, and
each legal zero-tile swap is an edge. BFS gives the minimum number of swaps.

## Complexity

- Time: O(6!), bounded by all board permutations
- Space: O(6!)
