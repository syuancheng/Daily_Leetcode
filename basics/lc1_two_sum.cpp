#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map; // num->index

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (const auto &iter = map.find(target - num); iter != map.end()) {
        return {iter->second, i};
      }
      map.insert(std::make_pair(num, i));
    }

    return {};
  }
};