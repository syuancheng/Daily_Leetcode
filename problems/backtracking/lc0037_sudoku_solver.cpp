#include <cstddef>
#include <vector>

using namespace std;

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
