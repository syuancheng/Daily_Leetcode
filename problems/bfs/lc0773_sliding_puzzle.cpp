#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start;
    for (const vector<int> &row : board) {
      for (int value : row) {
        start += static_cast<char>('0' + value);
      }
    }

    const string target = "123450";
    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);

    int depth = 0;
    while (!q.empty()) {
      int levelSize = static_cast<int>(q.size());
      for (int i = 0; i < levelSize; i++) {
        string cur = q.front();
        q.pop();

        if (cur == target) {
          return depth;
        }

        for (const string &next : getNeighbors(cur)) {
          if (visited.count(next) > 0) {
            continue;
          }
          q.push(next);
          visited.insert(next);
        }
      }
      depth++;
    }

    return -1;
  }

private:
  vector<string> getNeighbors(const string &board) {
    static const vector<vector<int>> mapping = {
        {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    vector<string> result;
    size_t zero = board.find('0');
    if (zero == string::npos) {
      return result;
    }

    for (int nextIndex : mapping[zero]) {
      result.push_back(swappedBoard(board, static_cast<int>(zero), nextIndex));
    }

    return result;
  }

  string swappedBoard(string board, int i, int j) {
    char temp = board[static_cast<size_t>(i)];
    board[static_cast<size_t>(i)] = board[static_cast<size_t>(j)];
    board[static_cast<size_t>(j)] = temp;
    return board;
  }
};
