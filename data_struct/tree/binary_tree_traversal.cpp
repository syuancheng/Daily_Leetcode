#include "../../problems/common/nodes.h"
#include <iostream>
#include <queue>
#include <vector>

class TreeState {
public:
  TreeNode *node;
  int depth;

  TreeState(TreeNode *node, int depth) : node(node), depth(depth) {}
};

// 二叉树的递归遍历框架
void traverse(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  std::cout << "enter " << root->val << '\n';

  /**
   * 三次经过一个节点：
   * 前序：第一次进入该节点。
   * 中序：该节点的左子树访问完，回退到该节点，准备遍历右子树。
   * 后序：该节点的左右子树都访问完，准备向父节点回退。
   */
  // 前序位置
  traverse(root->left);
  // 中序位置
  traverse(root->right);
  // 后序位置
}

class BinaryTreeTraversal {
private:
  std::vector<int> result;

public:
  void preorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    // 前序位置
    result.push_back(root->val);
    preorder(root->left);
    // 中序位置
    preorder(root->right);
    // 后序位置
  }

  void inorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    // 前序位置
    inorder(root->left);
    // 中序位置
    result.push_back(root->val);
    inorder(root->right);
    // 后序位置
  }

  void postorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    // 前序位置
    postorder(root->left);
    // 中序位置
    postorder(root->right);
    // 后序位置
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
    // 记录当前遍历到的层数，根节点视为第 1 层。
    [[maybe_unused]] int depth = 1;

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
      depth++;
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
