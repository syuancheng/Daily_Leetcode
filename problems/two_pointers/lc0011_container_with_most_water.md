# 11. Container With Most Water

## Labels

- Array
- Two Pointers
- Greedy

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/container-with-most-water/

## Problem Description

Choose two vertical lines that form a container with the maximum possible water area.

## My Solution

```cpp
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
```

## Complexity

- Time: O(n).
- Space: O(1).
