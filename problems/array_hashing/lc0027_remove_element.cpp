#include <vector>

using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }
      fast++;
    }
    return slow;//这里不需要+1， 因为slow索引是先复制，然后才++
  }
};
