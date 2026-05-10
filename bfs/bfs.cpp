#include <queue>
#include <unordered_set>

void bfs(int start) {
  std::queue<int> q;
  std::unordered_set<int> visited;

  q.push(start);
  visited.insert(start);

  while (!q.empty()) {
    int node = q.front(); // 取队首
    q.pop();              // 出队

    // 处理 node
    if (isTarget(node))
      return;

    // 扩展邻居
    for (int neighbor : getNeighbors(node)) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
  }
}