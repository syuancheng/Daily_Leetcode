## DFS / 回溯 完整笔记

---

## 第一性原理：本质是什么？

```
DFS / 回溯的本质：
  遍历一棵决策树
  每个节点 = 当前状态
  每条边   = 一个决策
  叶子     = 终止状态
```

所有 DFS / 回溯题目都可以用这个框架理解。

---

## 做题四步法

```
第一步：画决策树
  用小例子画出来
  看清楚每层的分支

第二步：问三个问题
  我在哪？     → 函数参数
  我能去哪？   → for 循环范围
  我要记录什么？→ 收集结果的时机

第三步：套模板写代码

第四步：验证边界
  空输入？
  单个元素？
  需要回溯吗？
```

---

## 核心模板

### 通用思考模板

```cpp
void dfs(参数) {
    // 1. 终止条件 / 收集结果
    if (终止条件) {
        收集结果;
        return;
    }

    // 2. 枚举所有决策
    for (枚举决策) {
        做选择;           // push / 标记
        dfs(下一个状态);  // 递归
        撤销选择;         // pop / 取消标记
    }
}
```

真正写代码前，先把这三个问题说清楚：

```text
1. 当前 dfs 的状态是什么？
2. dfs 要不要返回值？返回给上一层什么？
3. 答案是在递归返回值里，还是用全局变量/外部变量更新？
```

---

## 四种模式

### 模式一：树上返回值（自底向上）

```
特征：
  需要子节点的计算结果
  结果往上传递

决策树特征：
  没有"选择"，只有遍历
  不需要画决策树
  想清楚递推关系即可
```

```cpp
int dfs(TreeNode* node) {
    if (!node) return 0;           // 终止条件
    int left  = dfs(node->left);   // 拿左子树结果
    int right = dfs(node->right);  // 拿右子树结果
    return 用left和right计算当前答案; // 返回给父节点
}
```

**做题步骤：**
```
1. node==nullptr 返回什么？
2. 左右子树能给我什么？
3. 我怎么用左右结果算当前答案？
```

**例题：**
```
LC104 最大深度：return 1 + max(left, right)
LC543 二叉树直径：ans=max(ans,left+right)，return 1+max(left,right)
LC236 最近公共祖先：左右都找到了就是当前节点
```

**最重要的区别：**

```text
return 值：给父节点继续用的值
全局答案：当前节点自己能形成的候选答案
```

比如二叉树直径：

```cpp
int dfs(TreeNode* node) {
    if (!node) return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);

    ans = max(ans, left + right);      // 当前节点形成的直径
    return 1 + max(left, right);       // 返回给父节点的是高度
}
```

---

### 模式二：树上传参向下（自顶向下）

```
特征：
  需要从根到当前节点的信息
  信息往下传递

决策树特征：
  没有"选择"，只有遍历
  参数记录路径状态
```

```cpp
void dfs(TreeNode* node, int remain) {
    if (!node) return;

    remain -= node->val;              // 值传递，不需要恢复

    if (叶子节点) {
        判断 remain 是否满足条件;
        return;
    }

    dfs(node->left, remain);
    dfs(node->right, remain);
}
```

如果要记录路径，通常用引用传递 `path`，这时才需要回溯：

```cpp
void dfs(TreeNode* node, int remain, vector<int>& path) {
    if (!node) return;

    path.push_back(node->val);
    remain -= node->val;

    if (!node->left && !node->right && remain == 0) {
        result.push_back(path);
    }

    dfs(node->left, remain, path);
    dfs(node->right, remain, path);

    path.pop_back();                  // 引用传递，需要恢复现场
}
```

**做题步骤：**
```
1. 需要往下传什么参数？（路径/剩余sum）
2. 叶子节点时判断什么？
3. 需不需要回溯？（引用传递需要，值传递不需要）
```

**例题：**
```
LC112 路径总和：  传 remain，叶子判断 remain==0
LC113 路径总和II：传 path+remain，叶子收集 path
```

---

### 模式三：网格 DFS（扩散式）

```
特征：
  在二维网格上搜索
  向四个方向扩散

决策树特征：
  没有"选择"，只有扩散
  需要标记已访问
  永久标记不需要回溯
```

```cpp
void dfs(vector<vector<int>>& grid, int i, int j) {
    // 终止条件：越界 or 已访问
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (grid[i][j] == 0) return;

    grid[i][j] = 0;  // 标记已访问

    // 四个方向扩散
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}
```

**做题步骤：**
```
1. 终止条件：越界 + 不合法格子
2. 标记当前格子（防重复）
3. 四个方向递归
4. 要不要统计？（面积用返回值，数量在外层计数）
```

**例题：**
```
LC200 岛屿数量：  遇到1就DFS淹掉，count++
LC695 岛屿面积：  DFS返回面积，return 1+上+下+左+右
```

**什么时候网格 DFS 需要回溯？**

```text
永久改变地图：不需要回溯
  例：岛屿数量，把访问过的 1 改成 0

临时搜索路径：需要回溯
  例：单词搜索，当前路径不能重复使用格子，但换一条路径后格子还能再用
```

```cpp
bool dfs(vector<vector<char>>& board, int i, int j, int k) {
    if (k == word.size()) return true;
    if (越界 || board[i][j] != word[k]) return false;

    char old = board[i][j];
    board[i][j] = '#';                // 临时标记

    bool ok = dfs(board, i + 1, j, k + 1) ||
              dfs(board, i - 1, j, k + 1) ||
              dfs(board, i, j + 1, k + 1) ||
              dfs(board, i, j - 1, k + 1);

    board[i][j] = old;                // 回溯恢复
    return ok;
}
```

---

### 模式四：回溯（枚举所有可能）

```
特征：
  枚举所有可能的组合/排列
  需要"做选择"和"撤销选择"

决策树特征：
  需要画决策树
  每层有多个分支
  需要回溯
```

```cpp
// 子集 / 组合：start 控制后续选择范围
void dfs(int start, vector<int>& path) {
    // 收集结果（每层 or 叶子）
    if (满足条件) result.push_back(path);

    for (int i = start; i < n; i++) {
        path.push_back(nums[i]);  // 做选择
        dfs(i+1, path);           // 递归
        path.pop_back();          // 撤销选择
    }
}
```

排列题没有 `start`，因为每一层都可以从头选，只是不能重复选同一个位置：

```cpp
void dfs(vector<int>& path, vector<bool>& used) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        path.push_back(nums[i]);

        dfs(path, used);

        path.pop_back();
        used[i] = false;
    }
}
```

有重复元素时，先排序，再做同层去重：

```cpp
sort(nums.begin(), nums.end());

for (int i = start; i < nums.size(); i++) {
    if (i > start && nums[i] == nums[i - 1]) continue;
    path.push_back(nums[i]);
    dfs(i + 1, path);
    path.pop_back();
}
```

同层去重的核心是：

```text
i > start：说明这是同一层后面的分支
nums[i] == nums[i - 1]：这个值前面已经作为本层分支试过了
```

**做题步骤：**
```
1. 画决策树
2. 需不需要 start？
   有顺序限制（子集/组合）→ 需要 start
   无顺序限制（全排列）   → 需要 used[]
3. 什么时候收集结果？
   每层都收集（子集）
   叶子才收集（全排列/组合）
4. 剪枝条件是什么？
```

**例题：**
```
LC46  全排列：    used[]记录用过的，叶子收集
LC78  子集：      start控制范围，每层收集
LC131 分割回文串：start控制切割位置，叶子收集
LC93  复原IP：    start控制切割位置，4段且切完才收集
```

---

## 四种模式对比

| 模式 | 方向 | 需要画树 | 回溯 | 收集时机 |
|------|------|---------|------|---------|
| 树上返回值 | 自底向上 | ❌ | ❌ | return 时 |
| 树上传参 | 自顶向下 | ❌ | 看参数是否引用 | 叶子节点 |
| 网格 DFS | 四方向扩散 | ❌ | 看标记是否临时 | 计数/面积/路径 |
| 回溯 | 枚举选择 | ✅ | ✅ | 每层或叶子 |

---

## 关键决策点

### 需不需要 start？

```
[1,2] 和 [2,1] 是同一个？
  是（子集/组合/分割） → 需要 start
  否（全排列）         → 需要 used[]
```

### 需不需要回溯？

```
用引用传递 path？
  是 → 需要 pop_back
  否（值传递）→ 不需要，自动隔离

网格标记？
  永久标记（淹掉） → 不需要回溯
  临时标记        → 需要回溯
```

### 什么时候收集结果？

```
子集类：  每层都收集（进入函数就收集）
排列组合：叶子才收集（path.size()==n）
分割类：  start==s.size() 才收集
```

---

## 常见剪枝

```cpp
// 1. 超过限制段数
if (path.size() > 4) return;

// 2. 剩余元素不够
if (n - i < k - path.size()) return;

// 更常见的组合剪枝：直接缩小 for 循环范围
for (int i = start; i <= n - (k - path.size()) + 1; i++) {
    path.push_back(i);
    dfs(i + 1, path);
    path.pop_back();
}

// 3. 剩余字符长度不合法
int remain = s.size() - start;
int segments = 4 - path.size();
if (remain < segments || remain > segments * 3) return;

// 4. 不满足条件直接跳过
if (!isValid(sub)) continue;
```

---

## 去重问题

回溯去重最容易混，先问一句：

```text
我要去掉的是同一条路径里的重复使用，还是同一层的重复分支？
```

### 不能重复使用同一个元素

用 `used[i]`：

```cpp
if (used[i]) continue;
```

适合全排列。

### 不能产生重复答案

先排序，再跳过同一层重复值：

```cpp
sort(nums.begin(), nums.end());

for (int i = start; i < nums.size(); i++) {
    if (i > start && nums[i] == nums[i - 1]) continue;
    ...
}
```

适合子集 II、组合总和 II、带重复元素的分割/枚举题。

---

## 返回值 vs 外部变量

树形 DFS 里经常同时有两个值：

```text
1. 当前节点能往父节点贡献什么？
2. 当前节点能不能更新最终答案？
```

典型例子：

```text
LC104 最大深度：
  return 高度，答案就是 return 值

LC543 二叉树直径：
  return 高度
  ans 更新 left + right

LC124 二叉树最大路径和：
  return 单边最大贡献
  ans 更新 left + node + right

LC110 平衡二叉树：
  return 高度，或者 -1 表示已经不平衡
```

只要“父节点不能同时接收左右两边继续往上走”，就要特别小心：  
父节点通常只能拿到一个“单边贡献”，而最终答案可以在当前节点合并左右两边。

---

## 复杂度判断

```text
树 / 图 / 网格 DFS：
  每个节点或格子访问一次，通常 O(n) 或 O(m*n)

子集：
  一共有 2^n 个子集，时间 O(n * 2^n)，空间 O(n)

排列：
  一共有 n! 个排列，时间 O(n * n!)，空间 O(n)

组合：
  结果数量是 C(n,k)，时间通常按输出规模估算

分割字符串：
  切或不切的决策很多，最坏接近 O(n * 2^n)
```

复杂度不要只看递归深度，要看“递归树上一共有多少个状态/答案”。

---

## 做题checklist

```
□ 画出决策树（用小例子）
□ 确定函数参数（节点状态）
□ 确定 dfs 是否需要返回值
□ 区分 return 值和全局答案
□ 确定 for 循环范围（分支选择）
□ 确定收集时机（每层 or 叶子）
□ 确定需不需要 start or used[]
□ 确定是否需要排序去重
□ 确定需不需要回溯（pop_back）
□ 想想有没有剪枝可以加
□ 验证边界（空输入、单元素）
```

---

## 一句话总结

> DFS/回溯的本质是**遍历决策树**。先画树，再问"我在哪、能去哪、记录什么"，最后套模板。难点不在写代码，在于**把题目抽象成决策树**，这个能力只能靠不断画树来训练。
