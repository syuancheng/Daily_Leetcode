#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> map; // num -> index

    for (int i = 0; i < numbers.size(); i++) {
      int another = target - numbers[i];
      if (const auto &iter = map.find(another); iter != map.end()) {
        return {iter->second, i + 1};
      }
      map[numbers[i]] = i + 1;
    }
    return {};
  }
};
