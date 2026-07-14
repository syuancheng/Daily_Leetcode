#include <stack>

class MyQueue {
private:
  std::stack<int> inStack;
  std::stack<int> outStack;

  void moveInToOutIfNeeded() {
    if (!outStack.empty()) {
      return;
    }

    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

public:
  MyQueue() = default;

  void push(int x) { inStack.push(x); }

  int pop() {
    moveInToOutIfNeeded();
    const int result = outStack.top();
    outStack.pop();
    return result;
  }

  int peek() {
    moveInToOutIfNeeded();
    return outStack.top();
  }

  bool empty() { return inStack.empty() && outStack.empty(); }
};
