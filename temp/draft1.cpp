

// 基本的二叉树节点
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class State {
public:
  TreeNode *node;
  int depth;

  State(TreeNode *node, int depth) : node(node), depth(depth) {}
};

// 二叉树的递归遍历框架
void traverse(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  std::cout << "enter " << root->val << std::endl;

  /**
  三次经过node2 
  前序1.第一次进入node2
  中序2.当node2所有左子树访问完，回退到node2，准备去遍历右子树
  后续3.node2 左右子树都遍历完，准备向node2的父节点回退时
*/
  // 前序位置
  traverse(root->left);
  // 中序位置
  traverse(root->right);
  // 后序位置
}

class Solution {
private:
  std::vector<int> result;

public:
  void traversePreOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    // 前序位置
    result.push_back(root->val);
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
  }

  void traverseInOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    result.push_back(root->val);
    traverse(root->right);
    // 后序位置
  }

  void traversePostOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
    result.push_back(root->val);
  }

  void levelOrderTraverseV1(TreeNode *root) {
    if (!root) {
      return;
    }

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *cur = q.front();

      result.push_back(cur->val);
      q.pop();

      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
    }
  }

  void levelOrderTraverseV2(TreeNode *root) {
    if (!root) {
      return;
    }

    std::queue<TreeNode *> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        TreeNode *cur = q.front();

        q.pop();

        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      depth++;
    }
  }

  void levelOrderTraverseV3(TreeNode *root) {
    if (!root) {
      return;
    }

    std::queue<State> q;
    q.push(State(root, 1));

    while (!q.empty()) {
      State cur = q.front();
      q.pop();

      if (cur.node->left) {
        q.push(State(cur.node->left, cur.depth + 1));
      }
      if (cur.node->right) {
        q.push(State(cur.node->right, cur.depth + 1));
      }
    }
  }
};