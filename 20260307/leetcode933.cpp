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