# 51. N-Queens

## Labels

- Array
- Backtracking

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/n-queens/

## Problem Description

Place `n` queens on an `n x n` chessboard so that no two queens attack each
other. Return every distinct board configuration.

Each solution is represented as a vector of strings where `'Q'` marks a queen
and `'.'` marks an empty square.

## My Solution

```cpp
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    result_.clear();
    const size_t boardSize = static_cast<size_t>(n);
    vector<string> board(boardSize, string(boardSize, '.'));
    backtrack(board, 0, n);
    return result_;
  }

private:
  vector<vector<string>> result_;

  static size_t idx(int value) { return static_cast<size_t>(value); }

  void backtrack(vector<string> &board, int row, int n) {
    if (row == n) {
      result_.push_back(board);
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (!isValid(board, row, col, n)) {
        continue;
      }

      board[idx(row)][idx(col)] = 'Q';
      backtrack(board, row + 1, n);
      board[idx(row)][idx(col)] = '.';
    }
  }

  bool isValid(const vector<string> &board, int row, int col, int n) const {
    for (int i = 0; i < row; ++i) {
      if (board[idx(i)][idx(col)] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (board[idx(i)][idx(j)] == 'Q') {
        return false;
      }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[idx(i)][idx(j)] == 'Q') {
        return false;
      }
    }

    return true;
  }
};
```

## Complexity

- Time: O(n!), roughly one queen choice per row with pruning by occupied columns
  and diagonals.
- Space: O(n^2) for the board plus O(n) recursion depth, excluding the returned
  solutions.
