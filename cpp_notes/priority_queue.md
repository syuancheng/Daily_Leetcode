# C++ `std::priority_queue` Notes

## 1. Common Methods

- `q.push(val)`: Push an element into the heap and adjust its position automatically. Time complexity: O(log N).
- `q.pop()`: Remove the top element from the heap. Time complexity: O(log N).
- `q.top()`: Return a reference to the top element without removing it. Time complexity: O(1).
- `q.size()`: Return the number of elements currently in the heap.
- `q.empty()`: Return whether the heap is empty.

## 2. Default Declaration: Max-heap

The top element is always the maximum value. This is often used to maintain the smallest `k` values when solving for the `k`th smallest element.

```cpp
// Short form
priority_queue<int> max_heap;

// Full form, equivalent to the short form above
priority_queue<int, vector<int>, less<int>> max_heap;
```

## 3. Min-heap Declaration

The top element is always the minimum value. This is often used to maintain the largest `k` values when solving for the `k`th largest element.

```cpp
priority_queue<int, vector<int>, greater<int>> min_heap;
```

## 4. Custom Ordering

Core rule:

- To find the `k`th largest element, use a min-heap. For a custom comparator, use `>`.
- To find the `k`th smallest element, use a max-heap. For a custom comparator, use `<`.

Suppose we have the following structure:

```cpp
struct Node {
    int id;
    int weight;
};
```

### Option A: Custom Function Object

This is the most recommended style for interviews.

```cpp
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        // '>' creates a min-heap, so the node with smaller weight is on top.
        // '<' creates a max-heap, so the node with larger weight is on top.
        return a.weight > b.weight;
    }
};

priority_queue<Node, vector<Node>, Compare> q;
```

### Option B: Lambda Comparator

This is convenient for quick practice inside a function.

```cpp
auto cmp = [](const Node& a, const Node& b) {
    return a.weight > b.weight; // '>' creates a min-heap.
};

// The template parameter uses decltype(cmp), and the constructor must receive cmp.
priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);
```
