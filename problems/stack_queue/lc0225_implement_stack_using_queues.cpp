#include <cstddef>
#include <queue>

class MyStack {
private:
  std::queue<int> q;
  int topElement = 0;

public:
  MyStack() = default;

  void push(int x) {
    q.push(x);
    topElement = x;
  }

  int pop() {
    const size_t rotateCount = q.size() - 1;
    for (size_t i = 0; i < rotateCount; i++) {
      q.push(q.front());
      q.pop();
    }

    const int result = q.front();
    q.pop();
    if (!q.empty()) {
      topElement = q.back();
    }
    return result;
  }

  int top() { return topElement; }

  bool empty() { return q.empty(); }
};
