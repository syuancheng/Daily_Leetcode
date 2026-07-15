#include <cstddef>
#include <queue>
#include <vector>

using namespace std;

/*
BFS 核心笔记：

1. BFS 的队列不变量
   队列里保存的是“已经发现但还没有展开邻居”的节点。
   每次从队头取出的节点，都是当前已知距离最小的一批节点之一。

2. visited 的标记时机
   图 BFS 推荐“入队时标记 visited”，不是“出队时标记”。
   原因：同一个节点可能被多个前驱同时发现，如果等到出队才标记，它会被重复入队。

3. 三种常见写法
   - 普通队列：只保证能遍历到 reachable 节点。
   - 按层循环：外层每轮对应一层，适合求 step、层序结果、无权图最短距离。
   - 队列携带状态：把 depth/path/剩余次数等信息跟节点一起入队，适合状态更复杂的题。

4. BFS 和最短路
   普通 BFS 只适合无权图或所有边权相同的图。
   如果边权不同，队列的先进先出顺序不再等价于“距离最小优先”，需要 Dijkstra。
*/

namespace {

bool isValidVertex(int id, size_t size) {
  return id >= 0 && static_cast<size_t>(id) < size;
}

size_t toIndex(int id) { return static_cast<size_t>(id); }

} // namespace

class Node {
public:
  int val = 0;
  vector<Node *> children;
};

class TreeState {
public:
  Node *node = nullptr;
  int depth = 0;

  TreeState(Node *node, int depth) : node(node), depth(depth) {}
};

class GraphState {
public:
  int id = 0;
  int depth = 0;

  GraphState(int id, int depth) : id(id), depth(depth) {}
};

// BFS 写法一：普通队列遍历。
//
// 适用场景：
// - 只关心“能不能遍历到所有节点”。
// - 不需要知道当前层数、步数、路径长度。
// - 图结构必须配合 visited，否则有环时会死循环。
//
// 模板重点：
// - 树没有回边，一般不需要 visited。
// - 图可能有环，所以发现一个节点后要立刻标记 visited。
void levelOrderTraverse(Node *root) {
  if (root == nullptr) {
    return;
  }

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    // cur 是当前要展开的节点；它的孩子会被追加到队尾。
    Node *cur = q.front();
    q.pop();

    // 访问 cur 的位置。
    for (Node *child : cur->children) {
      if (child != nullptr) {
        q.push(child);
      }
    }
  }
}

void bfs(const vector<vector<int>> &graph, int source) {
  if (!isValidVertex(source, graph.size())) {
    return;
  }

  vector<bool> visited(graph.size(), false);
  queue<size_t> q;

  // 入队时标记 visited，保证同一个点最多入队一次。
  q.push(toIndex(source));
  visited[toIndex(source)] = true;

  while (!q.empty()) {
    size_t cur = q.front();
    q.pop();

    // 访问 cur 的位置。
    for (int next : graph[cur]) {
      if (!isValidVertex(next, graph.size())) {
        continue;
      }

      size_t nextIndex = toIndex(next);
      if (visited[nextIndex]) {
        continue;
      }

      // 这里不是等 next 出队后再标记，否则多个父节点会重复把它放进队列。
      q.push(nextIndex);
      visited[nextIndex] = true;
    }
  }
}

// BFS 写法二：按层遍历。
//
// 适用场景：
// - 需要知道当前层数 depth。
// - 需要按层收集结果，比如二叉树层序遍历。
// - 无权图最短步数：第一次到达某个节点时，当前 step 就是最短距离。
//
// 模板重点：
// - 每次 while 开始时，队列里的 size 个节点正好属于同一层。
// - 内层 for 只处理这一层；新入队的节点属于下一层，留到下一轮 while。
void levelOrderTraverseByLayer(Node *root) {
  if (root == nullptr) {
    return;
  }

  queue<Node *> q;
  q.push(root);

  // 根节点视为第 1 层。
  [[maybe_unused]] int depth = 1;

  while (!q.empty()) {
    // 必须先固定当前层的 size；不能在 for 条件里动态读取 q.size()。
    int size = static_cast<int>(q.size());
    for (int i = 0; i < size; i++) {
      Node *cur = q.front();
      q.pop();

      // 访问第 depth 层节点 cur 的位置。
      for (Node *child : cur->children) {
        if (child != nullptr) {
          q.push(child);
        }
      }
    }
    depth++;
  }
}

void bfsByLayer(const vector<vector<int>> &graph, int source) {
  if (!isValidVertex(source, graph.size())) {
    return;
  }

  vector<bool> visited(graph.size(), false);
  queue<size_t> q;

  q.push(toIndex(source));
  visited[toIndex(source)] = true;

  [[maybe_unused]] int step = 0;

  while (!q.empty()) {
    // 当前队列里的 size 个点距离 source 都是 step。
    int size = static_cast<int>(q.size());
    for (int i = 0; i < size; i++) {
      size_t cur = q.front();
      q.pop();

      // 访问距离 source 为 step 的节点 cur 的位置。
      for (int next : graph[cur]) {
        if (!isValidVertex(next, graph.size())) {
          continue;
        }

        size_t nextIndex = toIndex(next);
        if (visited[nextIndex]) {
          continue;
        }

        q.push(nextIndex);
        visited[nextIndex] = true;
      }
    }
    step++;
  }
}

// BFS 写法三：队列中携带状态。
//
// 适用场景：
// - 每个入队元素除了节点本身，还需要带 depth、路径、剩余次数等状态。
// - 不想用外层 size 循环，也能知道每个节点入队时的深度。
// - 题目状态不是单纯的“节点 id”，例如网格坐标、钥匙集合、剩余消除次数等。
//
// 注意：
// - 如果边权都相同，depth + 1 就是 BFS 最短步数。
// - 如果边权不同，普通 queue 不能保证最短路；求最短路应使用 Dijkstra。
// - 如果 visited 只按节点标记会误剪枝，就要把完整状态也纳入 visited。
void levelOrderTraverseWithState(Node *root) {
  if (root == nullptr) {
    return;
  }

  queue<TreeState> q;
  q.push(TreeState(root, 1));

  while (!q.empty()) {
    // depth 和 node 绑定在同一个状态里，不依赖外层按层循环。
    TreeState state = q.front();
    q.pop();

    Node *cur = state.node;
    [[maybe_unused]] int depth = state.depth;

    // 访问第 depth 层节点 cur 的位置。
    for (Node *child : cur->children) {
      if (child != nullptr) {
        q.push(TreeState(child, depth + 1));
      }
    }
  }
}

void bfsWithState(const vector<vector<int>> &graph, int source) {
  if (!isValidVertex(source, graph.size())) {
    return;
  }

  vector<bool> visited(graph.size(), false);
  queue<GraphState> q;

  // GraphState(source, 0) 表示 source 到自己的距离是 0。
  q.push(GraphState(source, 0));
  visited[toIndex(source)] = true;

  while (!q.empty()) {
    GraphState state = q.front();
    q.pop();

    int cur = state.id;
    [[maybe_unused]] int depth = state.depth;
    size_t curIndex = toIndex(cur);

    // 访问距离 source 为 depth 的节点 cur 的位置。
    for (int next : graph[curIndex]) {
      if (!isValidVertex(next, graph.size())) {
        continue;
      }

      size_t nextIndex = toIndex(next);
      if (visited[nextIndex]) {
        continue;
      }

      // 子节点的 depth 由父状态推出，不需要用当前层 size 统一维护。
      q.push(GraphState(next, depth + 1));
      visited[nextIndex] = true;
    }
  }
}
