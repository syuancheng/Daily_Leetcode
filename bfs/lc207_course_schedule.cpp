#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {//p[0] <- p[1]
    vector<vector<int>> graph(numCourses);
    vector<int> inDegrees(numCourses, 0);

    for (auto& p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      inDegrees[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < inDegrees.size(); ++i) {
      if (inDegrees[i] == 0) {
        q.push(i);
      }
    }

    int finished = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      finished++;
      for (auto n : graph[node]) {
        if (--inDegrees[n] == 0) {
          q.push(n);
        }
      }
    }

    return finished == numCourses;
  }
};
