#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    unordered_set<int> tmps;

    vector<int> ans;

    for (size_t i = 0; i < nums.size(); i++) {
      int val = nums.at(i);
      if (tmps.count(val) == 0) {
        ans.push_back(val);
        tmps.insert(val);
      }
    }

    nums.swap(ans);
    return nums.size();
  }

  int removeDuplicatesV2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};


int main() {

  return 0;
}