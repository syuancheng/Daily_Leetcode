#include <queue>
#include <vector>

class RecentCounter {
public:
  RecentCounter() {
  }

  int ping(int t) {
  };

private:
  std::vector<int> times;
};


class RecentCounterV2 {
public:
  RecentCounterV2() {
  }

  int ping(int t) {
  };

private:
  std::queue<int> times;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */