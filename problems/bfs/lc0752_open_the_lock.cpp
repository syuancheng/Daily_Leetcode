#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000") > 0) {
      return -1;
    }

    queue<string> q;
    unordered_set<string> visited;
    q.push("0000");
    visited.insert("0000");

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
          if (visited.count(next) > 0 || dead.count(next) > 0) {
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
  vector<string> getNeighbors(const string &s) {
    vector<string> result;
    for (int i = 0; i < 4; i++) {
      result.push_back(plusOne(s, i));
      result.push_back(minusOne(s, i));
    }
    return result;
  }

  string plusOne(string s, int i) {
    s[static_cast<size_t>(i)] =
        s[static_cast<size_t>(i)] == '9'
            ? '0'
            : static_cast<char>(s[static_cast<size_t>(i)] + 1);
    return s;
  }

  string minusOne(string s, int i) {
    s[static_cast<size_t>(i)] =
        s[static_cast<size_t>(i)] == '0'
            ? '9'
            : static_cast<char>(s[static_cast<size_t>(i)] - 1);
    return s;
  }
};
