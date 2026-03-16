#include <iostream>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int mid1 = 0, mid2 = 0;
    int n = nums1.size() + nums2.size();
    int i = 0, j = 0, k = 0;

    int mid = n / 2;

    while ((i < nums1.size() || j < nums2.size()) && k <= mid) {
      
      if (j >= nums2.size() || (i < nums1.size() && nums1[i] <= nums2[j])) {
        if (k == mid) {
          mid1 = nums1[i];
        } else if (k == mid - 1) {
          mid2 = nums1[i];
        }
        i++;
      } else {
        if (k == mid) {
          mid1 = nums2[j];
        } else if (k == mid - 1) {
          mid2 = nums2[j];
        }
        j++;
      }
      k++;
    }

    if (n % 2 == 1) {
      return mid1;
    } else {
      return (mid1 + mid2) / 2.0;
    }
  }
};

int main() {

  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};

  Solution s;
  double res = s.findMedianSortedArrays(nums1, nums2);

  cout << res << endl;

  return 0;
}