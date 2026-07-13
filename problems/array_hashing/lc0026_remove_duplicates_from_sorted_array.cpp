#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != nums[slow]) {
        slow++; //slow位置上的表示现有的元素，如何fast和slow不重复，那下一个slow位置就可以加入这个fast
        nums[slow] = nums[fast];
        
      }
      fast++;
    }
    return slow + 1;
  }
};