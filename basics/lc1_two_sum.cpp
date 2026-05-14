#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> m; // key: num, vlaue: index

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (auto iter = m.find(target - num); iter != m.end()) {
        return {iter->second, i};
      }
      m[num] = i;
    }
    return {};
  }
};
