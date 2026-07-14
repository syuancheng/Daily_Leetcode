#include <vector>

using namespace std;

class Solution {
public:
  // 记录递归堆栈中的节点
  vector<bool> onPath;
  // 记录图中是否有环
  bool hasCycle = false;

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
    onPath = vector<bool>(numCourses);

    for (int i = 0; i < numCourses; i++) {
      traverse(graph, i);
    }

    return !hasCycle;
  }

  void traverse(vector<vector<int>> &graph, int s) {
    if (hasCycle) {
      return;
    }

    if (onPath[s]) {
      hasCycle = true;
      return;
    }

    onPath[s] = true;
    for (auto n : graph[s]) {
      traverse(graph, n);
    }
    onPath[s] = false;
  }

  vector<vector<int>> buildGraph(int numCourses,
                                 vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < numCourses; i++) {
      graph[i] = vector<int>();
    }
    for (auto &edge : prerequisites) {
      int from = edge[1], to = edge[0];
      graph[from].push_back(to);
    }
    return graph;
  }
};

class Solution2 {
public:
  // 记录递归堆栈中的节点
  vector<bool> onPath;
  //记录节点是否被遍历过
  vector<bool> visited;
  // 记录图中是否有环
  bool hasCycle = false;

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
    onPath = vector<bool>(numCourses);
    visited = vector<bool>(numCourses);

    for (int i = 0; i < numCourses; i++) {
      traverse(graph, i);
    }

    return !hasCycle;
  }

  void traverse(vector<vector<int>> &graph, int s) {
    if (hasCycle) {
      return;
    }

    if (onPath[s]) {
      hasCycle = true;
      return;
    }

    if (visited[s]) {
      return;
    }

    onPath[s] = true;
    visited[s] = true;
    for (auto n : graph[s]) {
      traverse(graph, n);
    }
    onPath[s] = false;
  }

  vector<vector<int>> buildGraph(int numCourses,
                                 vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < numCourses; i++) {
      graph[i] = vector<int>();
    }
    for (auto &edge : prerequisites) {
      int from = edge[1], to = edge[0];
      graph[from].push_back(to);
    }
    return graph;
  }
};
