

#include <vector>
void backTracking() {
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
  }

public:
  std::vector<std::vector<int>> combine(int n, int k) {
  }
};
