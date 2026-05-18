# 207. Course Schedule

## Labels

- Graph
- BFS
- Topological Sort

## Mastery

- Attempts: X
- Status: Needs Review

## Link

https://leetcode.com/problems/course-schedule/

## Problem Description

Given `numCourses` courses labeled from `0` to `numCourses - 1` and a list of prerequisite pairs, determine whether it is possible to finish all courses. Each pair `[a, b]` means course `b` must be taken before course `a`.

## My Solution

```cpp
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &p : prerequisites) {
      graph[p[1]].push_back(p[0]); // 学完p1才能学p0
      inDegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    int finished = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      finished++;

      for (int next : graph[node]) {
        if (--inDegree[next] == 0) {
          q.push(next);
        }
      }
    }
    return finished == numCourses;
  }
};
```

## Complexity

- Time: O(V + E), where `V` is `numCourses` and `E` is the number of prerequisite pairs.
- Space: O(V + E), for the graph, indegree array, and queue.
