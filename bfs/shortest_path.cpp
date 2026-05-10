#include <queue>
#include <unordered_set>


int shortestPath(int start, int end) {
  std::queue<int> q;
  std::unordered_set<int> visited;

  q.push(start);
  visited.insert(start);
  int steps = 0;

  while (!q.empty()) {
    int size = q.size(); // ★ 一层一层处理

    for (int i = 0; i < size; ++i) {
      int node = q.front();
      q.pop();

      if (node == end)
        return steps;

      for (int next : getNext(node)) {
        if (visited.find(next) == visited.end()) {
          visited.insert(next);
          q.push(next);
        }
      }
    }

    steps++;
  }

  return -1;
}