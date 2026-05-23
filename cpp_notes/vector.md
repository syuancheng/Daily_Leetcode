## C++ vector 常用操作

### 增
| 操作 | 代码 |
|------|------|
| 末尾加入 | `v.push_back(1)` |
| 开头插入 | `v.insert(v.begin(), 1)` |
| 第i个位置插入 | `v.insert(v.begin() + i, 1)` |

### 删
| 操作 | 代码 |
|------|------|
| 删末尾 | `v.pop_back()` |
| 删开头 | `v.erase(v.begin())` |
| 删第i个元素 | `v.erase(v.begin() + i)` |
| 清空 | `v.clear()` |

### 查
| 操作 | 代码 |
|------|------|
| 访问第i个 | `v[i]` |
| 第一个 | `v.front()` |
| 最后一个 | `v.back()` |
| 元素个数 | `v.size()` |
| 是否为空 | `v.empty()` |

### 改
| 操作 | 代码 |
|------|------|
| 直接赋值 | `v[i] = 10` |

### ⚠️ 注意点
`erase` 和 `insert` 参数是迭代器，不是下标：
```cpp
v.erase(i);              // ❌ 编译报错
v.erase(v.begin() + i);  // ✅ 正确
```

### 回溯题常见用法
```cpp
// 做选择
nums.push_back(remain[i]);
remain.erase(remain.begin() + i);

// 撤销选择
remain.insert(remain.begin() + i, nums.back());
nums.pop_back();
```
