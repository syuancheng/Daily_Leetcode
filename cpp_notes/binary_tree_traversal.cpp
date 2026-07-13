#include "../problems/common/nodes.h"
#include <iostream>
#include <queue>
#include <vector>

class TreeState {
public:
  TreeNode *node;
  int depth;

  TreeState(TreeNode *node, int depth) : node(node), depth(depth) {}
};

void traverse(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  std::cout << "enter " << root->val << '\n';
  traverse(root->left);
  traverse(root->right);
}

class BinaryTreeTraversal {
private:
  std::vector<int> result;

public:
  void preorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    result.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
  }

  void inorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    inorder(root->left);
    result.push_back(root->val);
    inorder(root->right);
  }

  void postorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    postorder(root->left);
    postorder(root->right);
    result.push_back(root->val);
  }

  void levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();
      result.push_back(cur->val);

      if (cur->left != nullptr) {
        q.push(cur->left);
      }
      if (cur->right != nullptr) {
        q.push(cur->right);
      }
    }
  }

  void levelOrderByLayer(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = static_cast<int>(q.size());
      for (int i = 0; i < size; i++) {
        TreeNode *cur = q.front();
        q.pop();

        if (cur->left != nullptr) {
          q.push(cur->left);
        }
        if (cur->right != nullptr) {
          q.push(cur->right);
        }
      }
    }
  }

  void levelOrderWithDepth(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<TreeState> q;
    q.push(TreeState(root, 1));

    while (!q.empty()) {
      TreeState cur = q.front();
      q.pop();

      if (cur.node->left != nullptr) {
        q.push(TreeState(cur.node->left, cur.depth + 1));
      }
      if (cur.node->right != nullptr) {
        q.push(TreeState(cur.node->right, cur.depth + 1));
      }
    }
  }
};
