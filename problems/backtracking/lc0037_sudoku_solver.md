# 37. Sudoku Solver

## Labels

- Backtracking
- Matrix

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/sudoku-solver/

## Problem Description

Fill a partially completed `9 x 9` Sudoku board so that every row, column, and
`3 x 3` sub-box contains the digits `1` through `9` exactly once.

Empty cells are represented by `'.'`. The input board has exactly one solution,
and the board must be modified in place.

## My Solution

```cpp
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { solve(board, 0); }

private:
  static constexpr int kSize = 9;

  static size_t idx(int value) { return static_cast<size_t>(value); }

  bool solve(vector<vector<char>> &board, int cell) {
    if (cell == kSize * kSize) {
      return true;
    }

    const int row = cell / kSize;
    const int col = cell % kSize;

    if (board[idx(row)][idx(col)] != '.') {
      return solve(board, cell + 1);
    }

    for (char digit = '1'; digit <= '9'; ++digit) {
      if (!canPlace(board, row, col, digit)) {
        continue;
      }

      board[idx(row)][idx(col)] = digit;
      if (solve(board, cell + 1)) {
        return true;
      }
      board[idx(row)][idx(col)] = '.';
    }

    return false;
  }

  bool canPlace(const vector<vector<char>> &board, int row, int col,
                char digit) const {
    for (int i = 0; i < kSize; ++i) {
      if (board[idx(row)][idx(i)] == digit ||
          board[idx(i)][idx(col)] == digit) {
        return false;
      }

      const int boxRow = (row / 3) * 3 + i / 3;
      const int boxCol = (col / 3) * 3 + i % 3;
      if (board[idx(boxRow)][idx(boxCol)] == digit) {
        return false;
      }
    }

    return true;
  }
};
```

## Complexity

- Time: O(9^e), where `e` is the number of empty cells. Constraint checks are
  constant time for a fixed `9 x 9` board.
- Space: O(e) recursion depth in the worst case.
