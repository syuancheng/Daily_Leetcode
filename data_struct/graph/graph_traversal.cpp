#include <cstddef>
#include <iostream>
#include <vector>

class NaryNode {
public:
  int val = 0;
  std::vector<NaryNode *> children;
};

class Vertex {
public:
  int id = 0;
  std::vector<Vertex *> neighbors;
};

void traverseTree(NaryNode *root) {
  if (root == nullptr) {
    return;
  }

  // 前序位置
  std::cout << "visit " << root->val << '\n';
  for (NaryNode *child : root->children) {
    traverseTree(child);
  }
  // 后序位置
}

void traverseGraph(Vertex *source, std::vector<bool> &visited) {
  if (source == nullptr) {
    return;
  }

  size_t id = static_cast<size_t>(source->id);
  if (id >= visited.size() || visited[id]) {
    return; // 防止环导致死循环。
  }

  // 前序位置
  visited[id] = true;
  std::cout << "visit " << source->id << '\n';
  for (Vertex *neighbor : source->neighbors) {
    traverseGraph(neighbor, visited);
  }
  // 后序位置
}

void traverseGraph(const std::vector<std::vector<int>> &graph, int source,
                   std::vector<bool> &visited) {
  if (source < 0 || source >= static_cast<int>(graph.size())) {
    return;
  }

  size_t sourceIndex = static_cast<size_t>(source);
  if (visited[sourceIndex]) {
    return; // 防止环导致死循环。
  }

  // 前序位置
  visited[sourceIndex] = true;
  std::cout << "visit " << source << '\n';
  for (int to : graph[sourceIndex]) {
    traverseGraph(graph, to, visited);
  }
  // 后序位置
}

void traverseTreeBranches(NaryNode *root) {
  if (root == nullptr) {
    return;
  }

  for (NaryNode *child : root->children) {
    std::cout << "visit branch: " << root->val << " -> " << child->val
              << '\n';
    traverseTreeBranches(child);
  }
}

// 遍历图的边。visited[u][v] 表示边 u -> v 已经被遍历过。
void traverseEdges(Vertex *source, std::vector<std::vector<bool>> &visited) {
  if (source == nullptr) {
    return;
  }

  size_t from = static_cast<size_t>(source->id);
  if (from >= visited.size()) {
    return;
  }

  // 前序位置
  for (Vertex *neighbor : source->neighbors) {
    size_t to = static_cast<size_t>(neighbor->id);
    if (to >= visited[from].size() || visited[from][to]) {
      continue;
    }

    visited[from][to] = true;
    std::cout << "visit edge: " << source->id << " -> " << neighbor->id
              << '\n';
    traverseEdges(neighbor, visited);
  }
  // 后序位置
}

// 遍历邻接表表示的图中的边。
void traverseEdges(const std::vector<std::vector<int>> &graph, int source,
                   std::vector<std::vector<bool>> &visited) {
  if (source < 0 || source >= static_cast<int>(graph.size())) {
    return;
  }

  size_t from = static_cast<size_t>(source);
  if (from >= visited.size()) {
    return;
  }

  // 前序位置
  for (int next : graph[from]) {
    if (next < 0) {
      continue;
    }

    size_t to = static_cast<size_t>(next);
    if (to >= visited[from].size() || visited[from][to]) {
      continue;
    }

    visited[from][to] = true;
    std::cout << "visit edge: " << source << " -> " << next << '\n';
    traverseEdges(graph, next, visited);
  }
  // 后序位置
}

class TreePathPrinter {
private:
  std::vector<NaryNode *> path;

public:
  void printPathTo(NaryNode *root, NaryNode *target) {
    if (root == nullptr || target == nullptr) {
      return;
    }

    // 前序位置
    path.push_back(root);
    if (root->val == target->val) {
      std::cout << "find path: ";
      for (size_t i = 0; i < path.size(); i++) {
        if (i > 0) {
          std::cout << "->";
        }
        std::cout << path[i]->val;
      }
      std::cout << '\n';
      path.pop_back();
      return;
    }

    for (NaryNode *child : root->children) {
      printPathTo(child, target);
    }
    // 后序位置
    path.pop_back();
  }
};

// 遍历图的所有简单路径，寻找从 src 到 dest 的所有路径。
class GraphPathPrinter {
private:
  std::vector<bool> onPath;
  std::vector<int> path;

  void traverse(const std::vector<std::vector<int>> &graph, int src, int dest) {
    if (src < 0 || src >= static_cast<int>(graph.size())) {
      return;
    }

    size_t srcIndex = static_cast<size_t>(src);
    if (onPath[srcIndex]) {
      return; // 防止环导致死循环。
    }

    // 前序位置
    onPath[srcIndex] = true;
    path.push_back(src);

    if (src == dest) {
      std::cout << "find path: ";
      for (size_t i = 0; i < path.size(); i++) {
        if (i > 0) {
          std::cout << "->";
        }
        std::cout << path[i];
      }
      std::cout << '\n';
    } else {
      for (int to : graph[srcIndex]) {
        traverse(graph, to, dest);
      }
    }

    // 后序位置
    path.pop_back();
    onPath[srcIndex] = false;
  }

public:
  void printAllPaths(const std::vector<std::vector<int>> &graph, int src,
                     int dest) {
    onPath.assign(graph.size(), false);
    path.clear();
    traverse(graph, src, dest);
  }
};

class AllPathsSourceTarget {
private:
  std::vector<std::vector<int>> result;
  std::vector<int> path;

  void traverse(const std::vector<std::vector<int>> &graph, int src, int dest) {
    path.push_back(src);

    if (src == dest) {
      result.push_back(path);
      path.pop_back();
      return;
    }

    for (int to : graph[static_cast<size_t>(src)]) {
      traverse(graph, to, dest);
    }
    path.pop_back();
  }

public:
  std::vector<std::vector<int>>
  allPathsSourceTarget(const std::vector<std::vector<int>> &graph) {
    result.clear();
    path.clear();

    if (graph.empty()) {
      return result;
    }

    traverse(graph, 0, static_cast<int>(graph.size()) - 1);
    return result;
  }
};
