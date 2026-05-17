#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    // 排序规则：
    // 最高位大的在前，如果相同，则比较下一位。
    stable_sort(nums.begin(), nums.end(), [](const int &l, const int &r) {
      return to_string(l) + to_string(r) > to_string(r) + to_string(l);
    });//排序是关键
    if (nums[0] == '0') {
      return "0";
    }

    string res;
    for (int &num : nums) {
      res += to_string(num);
    }

    return res;
  }
};
