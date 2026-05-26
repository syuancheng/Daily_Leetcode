# 77. Combinations

## Labels

- Backtracking

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/combinations/

## Problem Description

Return all k-number combinations chosen from 1 to n.

## My Solution

```cpp


#include <vector>
void backTracking() {
  if (/**终止条件 */) {
    // 收集结果
    return;
  }
  // 单层搜索逻辑
  for (/**集合里的每一个元素，也可以是叶子节点的个数 */) {
    // 处理节点
    // 递归函数
    // 回溯操作，撤销梳理节点的情况
  }
  return;
}

// 组合是无序的

/**
1.递归函数参数 返回值
2.确定终止条件
3.单层递归逻辑
*/

/**
LC77
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。



示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
*/

class Solution {
private:
  std::vector<std::vector<int>> result;
  std::vector<int> path;
  // 1234 里取2个组合的数。 n=4, k=2
  void backTrack1(int n, int k, int start_idx) {
    if (path.size() == k) {
      result.push_back(path);
      return;
    }
    for (int i = start_idx; i <= n; i++) {
      path.push_back(i);
      backTrack1(n, k, i + 1);
      path.pop_back();
    }
  }

public:
  std::vector<std::vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backTrack1(n, k, 1);
    return result;
  }
};
```

## Complexity

- Time: O(C(n,k) * k).
- Space: O(k).
