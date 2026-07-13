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

    for (Node *child : root->children) {
      traverse(child);
    }
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

    while (!q.empty()) {
      int size = static_cast<int>(q.size());
      for (int i = 0; i < size; i++) {
        Node *cur = q.front();
        q.pop();

        for (Node *child : cur->children) {
          q.push(child);
        }
      }
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
