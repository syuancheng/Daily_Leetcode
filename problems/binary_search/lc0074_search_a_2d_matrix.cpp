#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0) {
      return false;
    }
    int m = matrix[0].size();
    if (m == 0) {
      return false;
    }

    int s = n * m;
    int l = 0, r = s - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      int val = matrix[mid / m][mid % m];
      if (val == target) {
        return true;
      } else if (val < target) {
        l = mid+1;
      } else {
        r = mid -1;
      }
    }
    return false;
  }
};