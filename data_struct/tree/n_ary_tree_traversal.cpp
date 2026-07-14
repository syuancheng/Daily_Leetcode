#include <queue>
#include <vector>

class Node {
public:
  int val = 0;
  std::vector<Node *> children;
};

class NaryState {
public:
  Node *node;
  int depth;

  NaryState(Node *node, int depth) : node(node), depth(depth) {}
};

class NaryTreeTraversal {
public:
  void traverse(Node *root) {
    if (root == nullptr) {
      return;
    }

    // 前序位置
    for (Node *child : root->children) {
      traverse(child);
    }
    // 后序位置
  }

  void levelOrder(Node *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      Node *cur = q.front();
      q.pop();

      for (Node *child : cur->children) {
        q.push(child);
      }
    }
  }

  void levelOrderByLayer(Node *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<Node *> q;
    q.push(root);
    // 记录当前遍历到的层数，根节点视为第 1 层。
    [[maybe_unused]] int depth = 1;

    while (!q.empty()) {
      int size = static_cast<int>(q.size());
      for (int i = 0; i < size; i++) {
        Node *cur = q.front();
        q.pop();

        for (Node *child : cur->children) {
          q.push(child);
        }
      }
      depth++;
    }
  }

  void levelOrderWithDepth(Node *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<NaryState> q;
    q.push(NaryState(root, 1));

    while (!q.empty()) {
      NaryState cur = q.front();
      q.pop();

      for (Node *child : cur.node->children) {
        q.push(NaryState(child, cur.depth + 1));
      }
    }
  }
};
