#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &p : prerequisites) {
      graph[p[1]].push_back(p[0]); // 学完p1才能学p0  p[0] <- p[1]
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
