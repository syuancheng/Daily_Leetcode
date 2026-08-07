#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  std::vector<Node *> children;
};

//多叉树遍历节点
void traverse(Node *root) {
  if (root == nullptr) {
    return;
  }

  // 前序位置
  std::cout << "visit " << root->val << std::endl;
  for (auto child : root->children) {
    traverse(child);
  }
  // 后续位置
}

class Vertex {
public:
  int id;
  std::vector<Vertex *> neighbors;
};

//图遍历节点
void traverse(Vertex *s, std::vector<bool> &visited) {
  if (s == nullptr) {
    return;
  }

  if (visited[s->id]) {
    return; // 防止死循环
  }
  // 前序位置
  visited[s->id] = true;
  for (auto n : s->neighbors) {
    traverse(s, visited);
  }
  // 后续位置
}
//图遍历节点，邻接表
void traverse(std::vector<std::vector<int>> &graph, int s,
              std::vector<bool> &visited) {
  if (s < 0 || s >= graph.size()) {
    return;
  }

  // 前序位置
  if (visited[s]) {
    return;
  }
  visited[s] = true;

  for (auto to : graph[s]) {
    traverse(graph, to, visited);
  }
  // 后续位置
}

//多叉树遍历边
void traverseBranch(Node *root) {
  if (root == nullptr) {
    return;
  }

  for (auto child : root->children) {
    std::cout << "visit branch: " << root->val << " -> " << child->val
              << std::endl;
    traverseBranch(child);
  }
}

// 遍历图的边
// 需要一个二维 visited 数组记录被遍历过的边，visited[u][v] 表示边 u->v
// 已经被遍历过
void traverseEdges(Vertex *s, vector<vector<bool>> &visited) {
  if (s == nullptr) {
    return;
  }

  // 前序位置
  for (auto neighbor : s->neighbors) {
    if (visited[s->id][neighbor->id]) {
      continue;
    }
    visited[s->id][neighbor->id] = true;
    cout << "visit edge: " << s->id << " -> " << neighbor->id << endl;
    traverseEdges(neighbor, visited);
  }

  // 后续位置
}
//使用领接表遍历图的边
void traverseEdges(std::vector<std::vector<int>> &graph, int s,
                   vector<vector<bool>> &visited) {
  if (s < 0 || s >= graph.size()) {
    return;
  }

  // 前序位置
  for (auto n : graph[s]) {
    if (visited[s][n]) {
      continue;
    }
    visited[s][n] = true;
    cout << "visit edge: " << s << " -> " << n << endl;
    traverseEdges(graph, n, visited);
  }

  // 后续位置
}

// 多叉树的遍历框架，寻找从根节点到目标节点的路径
class Solution0 {
private:
  vector<Node *> path;

public:
  void traverse(Node *root, Node *targetNode) {
    if (root == nullptr) {
      return;
    }

    // 前序位置
    if (root->val == targetNode->val) {
      // 找到目标节点
      cout << "find path: ";
      for (auto node : path) {
        cout << node->val << "->";
      }
      cout << targetNode->val << endl;
      return;
    }
    path.push_back(root);
    for (auto child : root->children) {
      traverse(child, targetNode);
    }
    // 后续位置
    path.pop_back();
  }
};

// 下面的算法代码可以遍历图的所有路径，寻找从 src 到 dest 的所有路径
class Solution1 {
private:
  vector<bool> onPath;
  vector<int> path;

public:
  void traverse(vector<vector<int>> &graph, int src, int dest) {

    if (src < 0 || src >= graph.size()) {
      return;
    }

    // 前序位置
    if (onPath[src]) {
      return; // 防止死循环
    }
    if (src == dest) {
      cout << "find path ";
      for (auto node : path) {
        cout << node << "->";
      }
      cout << dest << endl;
      return;
    }
    onPath[src] = true;
    path.push_back(src);
    for (auto to : graph[src]) {
      traverse(graph, to, dest);
    }
    // 后续位置
    path.pop_back();
    onPath[src] = false;
  }
};

class Solution3 {
private:
  vector<vector<int>> res;
  vector<int> path;

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    traverse(graph, 0, graph.size() - 1);
    return res;
  }

  void traverse(vector<vector<int>> &graph, int src, int dest) {
    path.push_back(src);

    if (src == dest) {
      res.push_back(path);
      path.pop_back();
      return;
    }

    for (auto to : graph[src]) {
      traverse(graph, to, dest);
    }
    path.pop_back();
  }
};
