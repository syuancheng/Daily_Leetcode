# 875. Koko Eating Bananas

## Labels

- Array
- Binary Search

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/koko-eating-bananas/

## Problem Description

Find the minimum integer eating speed `k` so Koko can finish all banana piles in
at most `h` hours.

## My Solution

Binary search the answer. If speed `k` can finish within `h` hours, every speed
larger than `k` also works, so move the right boundary left. Otherwise, `k` is
too slow.

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  long long hoursNeeded(const vector<int> &piles, int speed) {
    long long hours = 0;
    for (int pile : piles) {
      hours += (pile + speed - 1) / speed;
    }
    return hours;
  }

public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
      const int mid = left + (right - left) / 2;
      if (hoursNeeded(piles, mid) <= h) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};
```

## Complexity

- Time: O(n log m), where `m` is the largest pile.
- Space: O(1).
