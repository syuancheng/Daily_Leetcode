#include <cstddef>
#include <iostream>
#include <vector>

namespace {

bool isValidIndex(int id, size_t size) {
  return id >= 0 && static_cast<size_t>(id) < size;
}

size_t toIndex(int id) { return static_cast<size_t>(id); }

} // namespace

/*
Graph traversal state:

visited:
  A global/permanent mark. Once visited[u] becomes true, it stays true for the
  whole traversal. Use it when the goal is to visit every reachable vertex once,
  count connected components, or avoid repeating work in DFS/BFS.

onPath:
  A recursion-stack/local mark. Set onPath[u] = true when entering u, then reset
  it to false when backtracking out of u. Use it when the current path matters:
  cycle detection, or enumerating all simple paths. It blocks cycles inside one
  path, but allows the same vertex to appear in a different path later.

edgeVisited:
  A mark for edges instead of vertices. edgeVisited[u][v] means edge u -> v has
  already been traversed.
*/

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

// Section 1: tree-style traversal.
//
// A tree has no cycle, so no visited/onPath state is needed.
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

class TreePathPrinter {
private:
  std::vector<NaryNode *> path;

public:
  void printPathTo(NaryNode *root, NaryNode *target) {
    if (root == nullptr || target == nullptr) {
      return;
    }

    // 前序位置：先把当前节点放入路径。
    path.push_back(root);
    if (root == target) {
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
    // 后序位置：退出节点时恢复路径。
    path.pop_back();
  }
};

// Section 2: graph vertex traversal with visited.
//
// visited[u] means vertex u has been fully claimed by this traversal. It is a
// global mark, so it is not reset in the postorder position.
void traverseGraph(Vertex *source, std::vector<bool> &visited) {
  if (source == nullptr) {
    return;
  }

  if (!isValidIndex(source->id, visited.size())) {
    return;
  }

  size_t id = toIndex(source->id);
  if (visited[id]) {
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
  if (!isValidIndex(source, graph.size()) ||
      !isValidIndex(source, visited.size())) {
    return;
  }

  size_t sourceIndex = toIndex(source);
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

// Section 3: graph edge traversal with edgeVisited.
//
// edgeVisited[u][v] only records whether edge u -> v has been traversed. A
// vertex may still be reached multiple times through different incoming edges.
void traverseEdges(Vertex *source,
                   std::vector<std::vector<bool>> &edgeVisited) {
  if (source == nullptr) {
    return;
  }

  if (!isValidIndex(source->id, edgeVisited.size())) {
    return;
  }

  size_t from = toIndex(source->id);

  // 前序位置
  for (Vertex *neighbor : source->neighbors) {
    if (neighbor == nullptr ||
        !isValidIndex(neighbor->id, edgeVisited[from].size())) {
      continue;
    }

    size_t to = toIndex(neighbor->id);
    if (edgeVisited[from][to]) {
      continue;
    }

    edgeVisited[from][to] = true;
    std::cout << "visit edge: " << source->id << " -> " << neighbor->id
              << '\n';
    traverseEdges(neighbor, edgeVisited);
  }
  // 后序位置
}

// 遍历邻接表表示的图中的边。
void traverseEdges(const std::vector<std::vector<int>> &graph, int source,
                   std::vector<std::vector<bool>> &edgeVisited) {
  if (!isValidIndex(source, graph.size()) ||
      !isValidIndex(source, edgeVisited.size())) {
    return;
  }

  size_t from = toIndex(source);

  // 前序位置
  for (int next : graph[from]) {
    if (!isValidIndex(next, graph.size()) ||
        !isValidIndex(next, edgeVisited[from].size())) {
      continue;
    }

    size_t to = toIndex(next);
    if (edgeVisited[from][to]) {
      continue;
    }

    edgeVisited[from][to] = true;
    std::cout << "visit edge: " << source << " -> " << next << '\n';
    traverseEdges(graph, next, edgeVisited);
  }
  // 后序位置
}

// Section 4: all simple paths with onPath.
//
// onPath[u] means u is already on the current recursive call stack. It is reset
// in the postorder position, so another path can reuse u later.
class GraphPathPrinter {
private:
  std::vector<bool> onPath;
  std::vector<int> path;

  void traverse(const std::vector<std::vector<int>> &graph, int src, int dest) {
    if (!isValidIndex(src, graph.size())) {
      return;
    }

    size_t srcIndex = toIndex(src);
    if (onPath[srcIndex]) {
      return; // 当前路径里已经有 src，再进入会形成环。
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
    if (!isValidIndex(src, graph.size()) ||
        !isValidIndex(dest, graph.size())) {
      return;
    }

    onPath.assign(graph.size(), false);
    path.clear();
    traverse(graph, src, dest);
  }
};

// Section 5: LeetCode 797 style DAG path collection.
//
// The input is guaranteed to be a DAG, so a cycle-prevention onPath array is not
// required. For a general graph, use GraphPathPrinter's onPath pattern.
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

    for (int to : graph[toIndex(src)]) {
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
