# 347. Top K Frequent Elements

## Labels

- Hash Table
- Heap
- Bucket Sort

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/top-k-frequent-elements/

## Problem Description

Return the k most frequent elements.

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

- Time: O(n log k).
- Space: O(n).
