#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值
target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
*/
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          ans.push_back(i);
          ans.push_back(j);
          return ans;
        }
      }
    }
    return ans;
  }
};

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  unordered_map<int, int> hashtable;
  for (int i = 0; i < nums.size(); i++) {
    auto it = hashtable.find(target - nums[i]);
    if (it != hashtable.end()) {
      return {it->second, i};
    }
    hashtable[nums[i]] = i;
  }
  return {};
}

int main() {
  std::vector<int> tmp = {2, 7, 11, 15};
  auto res = twoSum(tmp, 9);

  std::cout << "1st:" << res[0] << ", 2nd: " << res[1] << std::endl;
  return 0;
}