#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if (n <= 2) {
        return nums.size();
      }

      int fast = 2, slow = 2;
      while (fast < n) {
        if (nums[fast] != nums[slow-2]) {
          nums[slow] = nums[fast];
          ++slow;
        }
        ++fast;
      }

      return slow;
    }
};

