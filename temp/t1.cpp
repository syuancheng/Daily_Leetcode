#include <queue>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> children;
};

class State {
public:
  Node *node;
  int depth;

  State(Node *node, int depth) : node(node), depth(depth) {}
};

class Solution {
private:
  std::vector<int> result;

public:
  void traverse(Node *root) {
    if (root == nullptr) {
      return;
    }

    // 前序位置
    for (Node *child : root->children) {
      traverse(child);
    }
    // 后续位置
  }

  void levelOrderTraverse(Node *root) {
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

  void levelOrderTravese2(Node *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<Node *> q;
    q.push(root);

    int depth = 1; // 记录当前遍历到的层数（根节点视为第 1 层）

    while (!q.empty()) {
      int sz = q.size();

      for (int i = 0; i < sz; i++) {
        Node *cur = q.front();
        q.pop();

        for (Node *child : cur->children) {
          q.push(child);
        }
      }
      depth++;
    }
  }

  void levelOrderTravese3(Node *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<State> q;
    q.push(State(root, 1));

    int depth = 1; // 记录当前遍历到的层数（根节点视为第 1 层）

    while (!q.empty()) {
      int sz = q.size();

      for (int i = 0; i < sz; i++) {
        State cur = q.front();
        q.pop();

        for (Node *child : cur.node->children) {
          q.push(State(child, 1+depth));
        }
      }
    }
  }
};