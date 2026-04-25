#include <algorithm>
#include <vector>
#include <string>

using namespace std;




class Solution {
public:
    string largestNumber(vector<int>& nums) {
      stable_sort(nums.begin(), nums.end(), [](const int &l, const int &r) {
        return to_string(l) + to_string(r) > to_string(r) + to_string(l);
      });
      if (nums[0] == 0) {
        return "0";
      }
      string ret;
      for (int& n : nums) {
        ret += to_string(n);
      }

      return ret;
    }
};