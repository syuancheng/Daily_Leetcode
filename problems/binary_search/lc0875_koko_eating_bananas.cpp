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
