# 1254. Number of Closed Islands

## Labels

- Array
- Matrix
- DFS

## Mastery

- Attempts: HO
- Status: Proficient

## Link

https://leetcode.com/problems/number-of-closed-islands/

## Problem Description

Given a grid where `0` is land and `1` is water, return the number of islands
fully surrounded by water. Land connected to the boundary is not closed.

## My Solution

First flood all boundary-connected land to water. After that, every remaining
land component must be closed, so count each component and flood it.

## Complexity

- Time: O(mn)
- Space: O(mn) worst-case recursion stack
