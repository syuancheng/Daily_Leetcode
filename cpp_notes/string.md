## C++ string 常用操作

### 增
| 操作 | 代码 |
|------|------|
| 末尾加入字符 | `s.push_back('a')` |
| 末尾加入字符（简写） | `s += 'a'` |
| 末尾加入字符串 | `s += "abc"` |
| 第i个位置插入字符串 | `s.insert(i, "abc")` |

### 删
| 操作 | 代码 |
|------|------|
| 删末尾字符 | `s.pop_back()` |
| 从第i个位置删n个字符 | `s.erase(i, n)` |
| 清空 | `s.clear()` |

### 查
| 操作 | 代码 |
|------|------|
| 访问第i个字符 | `s[i]` |
| 第一个字符 | `s.front()` |
| 最后一个字符 | `s.back()` |
| 字符个数 | `s.size()` 或 `s.length()` |
| 是否为空 | `s.empty()` |
| 查找子串（返回下标） | `s.find("abc")` |
| 找不到时的返回值 | `string::npos` |

### 截取
| 操作 | 代码 |
|------|------|
| 从第i个到末尾 | `s.substr(i)` |
| 从第i个开始取n个字符 | `s.substr(i, n)` |

### 类型转换
| 操作 | 代码 |
|------|------|
| int → string | `to_string(123)` |
| string → int | `stoi("123")` |
| string → long long | `stoll("123")` |

### split
C++ `std::string` 没有 Go `strings.Split` 那样的内置方法，可以自己写一个 helper。

```cpp
std::vector<std::string> split(const std::string &s,
                               const std::string &separator) {
  std::vector<std::string> result;

  if (separator.empty()) {
    for (char c : s) {
      result.push_back(std::string(1, c));
    }
    return result;
  }

  size_t start = 0;
  while (true) {
    size_t pos = s.find(separator, start);
    if (pos == std::string::npos) {
      result.push_back(s.substr(start));
      break;
    }

    result.push_back(s.substr(start, pos - start));
    start = pos + separator.size();
  }

  return result;
}
```

完整 helper 在 [string_split.cpp](string_split.cpp)。

### 与 vector 的区别
| 操作 | vector | string |
|------|--------|--------|
| 末尾加入 | `push_back(1)` | `push_back('a')` 或 `+= 'a'` |
| 删末尾 | `pop_back()` | `pop_back()` |
| 截取 | 无 | `substr(i, n)` |
| 插入 | `insert(v.begin()+i, val)` | `insert(i, str)` 不需要迭代器 |
| 删除 | `erase(v.begin()+i)` | `erase(i, n)` 不需要迭代器 |

### 回溯题常见用法
```cpp
// 做选择
s += 'a';

// 撤销选择
s.pop_back();

// 记录结果
result.push_back(s);

// 截取子串判断
s.substr(0, 3) == "abc";
```
