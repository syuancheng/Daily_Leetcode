# 543. Diameter of Binary Tree

## Labels

- Tree
- DFS

## Mastery

- Attempts: OOH
- Status: Familiar

## Link

https://leetcode.com/problems/diameter-of-binary-tree/

## Problem Description

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root, and its length is counted by number of edges.

Example:

```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: The longest path is [4,2,1,3] or [5,2,1,3].
```

## My Solution

```cpp
#include "../common/nodes.h"
#include <algorithm>

class Solution {
private:
  int result = 0;

public:
  int dfsLen(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int l = dfsLen(node->left);
    int r = dfsLen(node->right);

    result = std::max(result, l + r ); //这里就设想，如果一个树就三个node，root和它 点左右子节点，那么就等于他的左右子树depth之和。

    return std::max(l, r) + 1;//这里必须+1, 如果一个树只有一个node。那么他的depth应该是1
  }

  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    dfsLen(root);
    return result;
  }

  // int diameterOfBinaryTree(TreeNode *root) {
  //   if (root == nullptr) {
  //     return 0;
  //   }
  //   int l = diameterOfBinaryTree(root->left);
  //   int r = diameterOfBinaryTree(root->right);

  //   result = std::max(result, l + r);

  //   return std::max(l, r);  // 这里必须返回result啊啊啊啊啊
  // }
};
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the tree. Each node is visited once.
- Space: O(h), where `h` is the height of the tree, due to the recursion stack.
