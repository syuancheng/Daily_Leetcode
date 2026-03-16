#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (n < 1) {
      return;
    }

    int idx1 = m > 0 ? m - 1 : -1, idx2 = n - 1;

    for (int i = m + n - 1; i >= 0; i--) {
      if (idx2 < 0) {
        break;
      } else {
        if (idx1 < 0) {
          nums1[i] = nums2[idx2];
          idx2--;
          continue;
        }
      }

      if (nums1[idx1] >= nums2[idx2]) {
        nums1[i] = nums1[idx1];
        idx1--;
      } else {
        nums1[i] = nums2[idx2];
        idx2--;
      }
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  Solution s;
  s.merge(nums1, m, nums2, n);

  return 0;
}
