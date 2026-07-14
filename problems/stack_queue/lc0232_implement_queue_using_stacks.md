# 232. Implement Queue using Stacks

## Labels

- Stack
- Queue
- Design

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/implement-queue-using-stacks/

## Problem Description

Implement a first-in-first-out queue using stacks.

## My Solution

Use two stacks:

- `inStack` receives newly pushed values.
- `outStack` serves the queue front.

Only move values from `inStack` to `outStack` when `outStack` is empty. This
reverses insertion order exactly once per element.

```cpp
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
```

## Complexity

- Amortized time: O(1) per operation.
- Worst-case `pop` / `peek`: O(n) when transferring stacks.
- Space: O(n).
