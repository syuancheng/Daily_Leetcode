#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    if (height.size() < 2) {
      return 0;
    }
    int maxArea = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      int area = (right - left) * min(height[left], height[right]);
      maxArea = max(maxArea, area);
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return maxArea;
  }
};