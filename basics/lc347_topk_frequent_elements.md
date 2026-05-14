# 347. Top K Frequent Elements

## Labels

- Hash Table
- Heap

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/top-k-frequent-elements/

## Problem Description

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. The answer can be returned in any order.

## My Solution

```cpp
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  static bool compare(pair<int, int> &m, pair<int, int> &n) {
    return m.second > n.second;
  }

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> occurrences; // int -> count
    for (auto num : nums) {
      occurrences[num]++;
    }

    std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                        decltype(&compare)>
        heap(compare);

    for (auto &[num, count] : occurrences) {
      if (heap.size() == k) {
        if (heap.top().second < count) {
          heap.pop();
          heap.emplace(num, count);
        }
      } else {
        heap.emplace(num, count);
      }
    }

    vector<int> ans;
    while (!heap.empty()) {
      ans.push_back(heap.top().first);
      heap.pop();
    }

    return ans;
  }
};
```

## Complexity

- Time: O(n log k), where `n` is the length of `nums`.
- Space: O(n + k), for the frequency map and heap.
