#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

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