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

int sumNodes(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  return sumNodes(root->left) + sumNodes(root->right) + root->val;
}

class Solution {
public:
  long long prev = LONG_MIN; // 外部状态，用来辅助“本层逻辑”

  bool isValidBST(TreeNode *root) {
    // 【第一步：找终点】
    if (root == nullptr)
      return true;

    // 【第二步：托付给下属 A (左子树)】
    // 契约：只要左边有一丁点不合法，我这一层直接报失败
    if (!isValidBST(root->left))
      return false;

    // 【第三步：本层逻辑 —— 经理亲自出手】
    // 契约核心：中序遍历到我这里时，我的值必须比刚才（左边）处理完的值大
    if (root->val <= prev)
      return false;
    prev = root->val; // 这里的赋值，是为接下来的右子树下属准备“参考值”

    // 【第四步：托付给下属 B (右子树)】
    // 最后的成败，取决于右子树的契约执行结果
    return isValidBST(root->right);
  }
};

