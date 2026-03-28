#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int length = nums.size();

      vector<int> left(length, 0), right(length, 0);

      vector<int> ans(length);

      left[0] = 1;
      for (int i = 1; i<length; i++) {
        left[i] = nums[i-1] * left[i-1];
      }

      right[length - 2] = 1;
      for (int i = length-1; i >=0; i--) {
        right[i] = nums[i+1] * right[i+1];
      }

      for (int i =0; i < length; i++) {
        ans[i] = left[i]* right[i];
      }

      return ans;
    }

        vector<int> productExceptSelfV2(vector<int>& nums) {
          int length = nums.size();
          
      vector<int> ans(length);

      ans[0] = 1;
      for (int i = 1; i<length; i++) {
        ans[i] = nums[i-1] * ans[i-1];
      }

      int r = 1;
      for (int i = length-1; i >=0; i--) {
        ans[i] = ans[i] * r;

        r*= nums[i];
      }
      return ans;
    }
};