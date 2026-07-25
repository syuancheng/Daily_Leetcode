#include <vector>

using namespace std;

class Solution {
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    result.clear();
    if (n == 1) {
      for (int digit = 0; digit <= 9; digit++) {
        result.push_back(digit);
      }
      return result;
    }

    for (int digit = 1; digit <= 9; digit++) {
      backtrack(n, k, 1, digit);
    }
    return result;
  }

private:
  vector<int> result;

  void backtrack(int n, int k, int length, int value) {
    if (length == n) {
      result.push_back(value);
      return;
    }

    int lastDigit = value % 10;
    int nextUp = lastDigit + k;
    if (nextUp <= 9) {
      backtrack(n, k, length + 1, value * 10 + nextUp);
    }

    int nextDown = lastDigit - k;
    if (k != 0 && nextDown >= 0) {
      backtrack(n, k, length + 1, value * 10 + nextDown);
    }
  }
};
