# 933. Number of Recent Calls

## Labels

- Queue
- Design
- Data Stream

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/number-of-recent-calls/

## Problem Description

Count recent pings in the last 3000 milliseconds.

## My Solution

```cpp
#include <queue>
#include <vector>

class RecentCounter {
public:
  RecentCounter() {}

  int ping(int t) {
    int ans = 0;
    times.emplace_back(t);
    for (const auto req_time : times) {
      if (req_time < (t - 3000)) {
        continue;
      }
      ans++;
    }
    return ans;
  };

private:
  std::vector<int> times;
};


class RecentCounterV2 {
public:
  RecentCounterV2() {}

  int ping(int t) {
    times.push(t);
    while (times.front() < t -3000) {
        times.pop();
    }
    return times.size();
  };

private:
  std::queue<int> times;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```

## Complexity

- Time: O(1) amortized.
- Space: O(n).
