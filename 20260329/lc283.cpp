#include <vector>

using namespace std;

//[0,0,1,0,3,12]
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    if (nums.size() < 2) {
      return;
    }

    int fast = 1;
    for (int slow = 0; slow < nums.size(); slow++) {
      if (fast >= nums.size()) {
        break;
      }
      if (nums[slow] != 0) {
        continue;
      }
      if (fast <= slow) {
        fast = slow + 1;
      }
      while (fast < nums.size()) {
        if (nums[fast] != 0) {
          nums[slow] = nums[fast];
          nums[fast++] = 0;
          break;
        }
        fast++;
      }
    }
  }
};