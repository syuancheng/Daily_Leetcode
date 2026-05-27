# 144. Binary Tree Preorder Traversal

## Labels

- Tree
- DFS
- Stack

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/binary-tree-preorder-traversal/

## Problem Description

Return the preorder traversal of a binary tree.

## My Solution

```cpp
#include "type.h"
#include <cstddef>
#include <stack>
#include <vector>

using namespace std;


/**
144. 二叉树的前序遍历
中左右
*/

class Solution {
public:
  void preOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    preOrder(root, ans);
    return ans;
  }

  void preOrder2(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    stack<TreeNode *> sk;
    sk.push(root);

    while (!sk.empty()) {
      TreeNode *curr = sk.top();
      sk.pop();
      res.push_back(curr->val);

      if (curr->right) {
        sk.push(curr->right);
      }
      if (curr->left) {
        sk.push(curr->left);
      }
    }
    return;
  }

  vector<int> preorderTraversalWithMrios(TreeNode *root) {
    vector<int> ans;
    
    if (root == nullptr) {
        return ans;
    }

    TreeNode *p1 = root, *p2 = nullptr;

    while (p1 != nullptr) {
      p2 = p1->left;
      if (p2 != nullptr) {
        while (p2->right != nullptr && p2->right != p1) {
            p2 = p2->right;
        }
        if (p2->right == nullptr) {
          ans.emplace_back(p1->val);
          p2->right = p1;
          p1 = p1->left;
          continue;
        } else {
          p2->right = nullptr;
        }
      } else {
        ans.emplace_back(p1->val);
      }
      p1 = p1->right;
    }
    
    return ans;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(h).
