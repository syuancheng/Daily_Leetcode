#include <vector>

using namespace std;

//[0,0,1,0,3,12]
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i = removeElement(nums, 0);
    for (; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }

  // 双指针技巧，复用 [27. 移除元素] 的解法。
  int removeElement(vector<int> &nums, int val) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }
      fast++;
    }
    return slow;
  }
};