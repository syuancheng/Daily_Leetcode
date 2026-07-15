#include <algorithm>
#include <cstddef>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> graph;
  vector<bool> visited;
  vector<bool> onPath;
  vector<int> postorder;
  bool hasCycle = false;

  bool isValidCourse(int course) const {
    return course >= 0 && static_cast<size_t>(course) < graph.size();
  }

  void traverse(int course) {
    if (hasCycle || !isValidCourse(course)) {
      return;
    }

    const size_t index = static_cast<size_t>(course);
    if (onPath[index]) {
      hasCycle = true;
      return;
    }
    if (visited[index]) {
      return;
    }

    onPath[index] = true;
    visited[index] = true;
    for (int next : graph[index]) {
      traverse(next);
    }
    onPath[index] = false;
    postorder.push_back(course);
  }

  void buildGraph(int numCourses, const vector<vector<int>> &prerequisites) {
    /**
      prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi, bi -> ai
    */
    graph.assign(static_cast<size_t>(numCourses), {});
    for (const vector<int> &edge : prerequisites) {
      if (edge.size() < 2) {
        continue;
      }

      const int from = edge[1];
      const int to = edge[0];
      if (from < 0 || to < 0 || from >= numCourses || to >= numCourses) {
        continue;
      }
      graph[static_cast<size_t>(from)].push_back(to);
    }
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses <= 0) {
      return {};
    }

    buildGraph(numCourses, prerequisites);
    visited.assign(static_cast<size_t>(numCourses), false);
    onPath.assign(static_cast<size_t>(numCourses), false);
    postorder.clear();
    hasCycle = false;

    for (int course = 0; course < numCourses; course++) {
      traverse(course);
    }

    if (hasCycle) {
      return {};
    }

    reverse(postorder.begin(), postorder.end());
    return postorder;
  }
};
