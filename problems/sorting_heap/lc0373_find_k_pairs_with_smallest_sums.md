# 373. Find K Pairs with Smallest Sums

## Labels

- Array
- Heap

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

## Problem Description

Given two sorted arrays, return up to k pairs with the smallest sums, where each pair contains one number from each array.

## My Solution

```cpp
#include <cstddef>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  struct Entry {
    int sum;
    size_t nums1Index;
    size_t nums2Index;
  };

public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k <= 0) {
      return result;
    }

    auto cmp = [](const Entry &a, const Entry &b) { return a.sum > b.sum; };
    priority_queue<Entry, vector<Entry>, decltype(cmp)> pq(cmp);

    for (size_t i = 0; i < nums1.size(); i++) {
      pq.push({nums1[i] + nums2[0], i, 0});
    }

    while (!pq.empty() && k > 0) {
      Entry cur = pq.top();
      pq.pop();
      k--;

      result.push_back({nums1[cur.nums1Index], nums2[cur.nums2Index]});

      size_t nextIndex = cur.nums2Index + 1;
      if (nextIndex < nums2.size()) {
        pq.push({nums1[cur.nums1Index] + nums2[nextIndex], cur.nums1Index,
                 nextIndex});
      }
    }

    return result;
  }
};
```

## Complexity

- Time: O(m log m + k log m), where m is nums1.size().
- Space: O(m).
