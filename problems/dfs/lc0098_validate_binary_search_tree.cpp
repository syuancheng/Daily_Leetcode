#include "type.h"
#include <climits>

/**
递归
1.找终点：空了就回，别死循环。（代码里的 if (!root)）

2.定契约：明确函数是干嘛的，别在脑子里模拟跳跃。

3.托付并汇总：

a.托付：调用自己去处理更小的子问题（代码里的 serialize(left)）。

b.汇总（本层逻辑）：把托付回来的结果，加上自己这一层的加工，交给上级（代码里的
to_string + l + r）。
*/
class Solution {
public:
  long long prev = LONG_MIN; // 外部状态，用来辅助“本层逻辑”

  bool isValidBST(TreeNode *root) {
  }
};
