# 225. Implement Stack using Queues

## Labels

- Stack
- Queue
- Design

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/implement-stack-using-queues/

## Problem Description

Implement a last-in-first-out stack using queues.

## My Solution

Use one queue. `push` appends normally and records the latest element as
`topElement`. For `pop`, rotate the first `n - 1` elements to the back, so the
last pushed element moves to the front and can be removed.

```cpp
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
```

## Complexity

- `push`: O(1).
- `pop`: O(n).
- `top`: O(1).
- `empty`: O(1).
- Space: O(n).
