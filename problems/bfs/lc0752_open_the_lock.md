# 752. Open the Lock

## Labels

- BFS
- Hash Table
- String

## Mastery

- Attempts: HO
- Status: Proficient

## Link

https://leetcode.com/problems/open-the-lock/

## Problem Description

Starting from `"0000"`, each move turns one wheel one step forward or backward.
Return the minimum number of moves to reach `target`, avoiding all deadends.

## My Solution

This is an unweighted shortest-path search over lock states, so use BFS. Mark a
state visited when it is pushed into the queue to avoid duplicate enqueues.

## Complexity

- Time: O(10^4), because there are at most ten thousand lock states
- Space: O(10^4)
