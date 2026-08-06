#include <vector>

using namespace std;

class Solution {
public:

  vector<bool> onPath;

  bool hasCycle = false;

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    (void)numCourses;
    (void)prerequisites;
    return false;
  }

  void traverse(vector<vector<int>> &graph, int s) {
    (void)graph;
    (void)s;
  }

  vector<vector<int>> buildGraph(int numCourses,
                                 vector<vector<int>> &prerequisites) {
                                   (void)numCourses;
                                   (void)prerequisites;
                                   return {};
                                 }
};

class Solution2 {
public:

  vector<bool> onPath;

  vector<bool> visited;

  bool hasCycle = false;

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    (void)numCourses;
    (void)prerequisites;
    return false;
  }

  void traverse(vector<vector<int>> &graph, int s) {
    (void)graph;
    (void)s;
  }

  vector<vector<int>> buildGraph(int numCourses,
                                 vector<vector<int>> &prerequisites) {
                                   (void)numCourses;
                                   (void)prerequisites;
                                   return {};
                                 }
};
