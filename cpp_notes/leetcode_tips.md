## 刷题常用技巧详解

---

## 1. 字符串转数字

### 整数 atoi
```cpp
// "123" → 123
string s = "123";
int num = 0;
for (char c : s) {
    num = num * 10 + (c - '0');
}
// num = 123

// 追踪：
// c='1': num = 0*10 + 1 = 1
// c='2': num = 1*10 + 2 = 12
// c='3': num = 12*10 + 3 = 123
```

### 负数
```cpp
// "-123" → -123
int sign = 1, i = 0;
if (!s.empty() && s[0] == '-') { sign = -1; i = 1; }
int num = 0;
for (; i < s.size(); i++) {
    num = num * 10 + (s[i] - '0');
}
return sign * num;
```

### 小数 atof
```cpp
// "3.14" → 3.14
int i = 0;
double result = 0.0;

// 整数部分
while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
    result = result * 10 + (s[i] - '0');
    i++;
}

// 小数部分
if (i < s.size() && s[i] == '.') {
    i++;
    double factor = 0.1;
    while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
        result += (s[i] - '0') * factor;
        factor *= 0.1;
        i++;
    }
}
// result = 3.14
```

### 数字转字符串
```cpp
// 123 → "123"
int num = 123;
string s = "";
while (num > 0) {
    s += (char)('0' + num % 10);  // 取个位
    num /= 10;
}
reverse(s.begin(), s.end());  // 反转
// s = "123"

// 注意：上面没有处理 0 和负数。更完整的手写版本：
int x = -123;
if (x == 0) return "0";

bool neg = x < 0;
long long num = x;      // 用 long long 避免 INT_MIN 取反溢出
if (neg) num = -num;

string ans;
while (num > 0) {
    ans.push_back(char('0' + num % 10));
    num /= 10;
}
if (neg) ans.push_back('-');
reverse(ans.begin(), ans.end());
```

---

## 2. 字符操作

### 字母和数字互转
```cpp
// 字母 → 下标
// 'a' - 'a' = 0
// 'b' - 'a' = 1
// 'z' - 'a' = 25

// 下标 → 字母
// char('a' + 0) = 'a'
// char('a' + 25) = 'z'

// 用途：统计字母频率
int freq[26] = {0};
for (char c : s) {
    freq[c - 'a']++;  // 'a'→0, 'b'→1...
}
```

### 大小写转换
```cpp
// 方法1：标准库
char lower = static_cast<char>(tolower(static_cast<unsigned char>('A')));  // → 'a'
char upper = static_cast<char>(toupper(static_cast<unsigned char>('a')));  // → 'A'

// 方法2：位运算（只适合 ASCII 英文字母）
'A' | 32   // → 'a'（转小写）
'a' & ~32  // → 'A'（转大写）

// 追踪：
// 'A' = 01000001
// 32  = 00100000
// OR  = 01100001 = 'a' ✅
```

### 判断字符类型
```cpp
isdigit(static_cast<unsigned char>('3'))   // true，是数字
isalpha(static_cast<unsigned char>('a'))   // true，是字母
isalnum(static_cast<unsigned char>('a'))   // true，是字母或数字
isspace(static_cast<unsigned char>(' '))   // true，是空格

// 说明：<cctype> 里的 isdigit/isalpha/tolower 等函数，传 char 时最好转 unsigned char。
// 这样可以避免 char 为负值时出现未定义行为。

// 用途：LC65 有效数字
for (char c : s) {
    if (!isdigit(static_cast<unsigned char>(c)) && c != '.' && c != 'e') return false;
}
```

---

## 3. 位运算

### 判断奇偶
```cpp
// 比 n%2 更快
if (n & 1) // 奇数
else       // 偶数

// 用途：LC231 2的幂
// 2的幂二进制只有一个1
// 4 = 100, 8 = 1000
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n-1)) == 0;
}
// n=4:   100 & 011 = 0 ✅
// n=6:   110 & 101 = 100 ≠ 0 ❌
```

### 异或
```cpp
// 性质：
// a ^ a = 0  相同数异或为0
// a ^ 0 = a  任何数和0异或为本身
// 交换律：a ^ b = b ^ a

// 用途：LC136 找只出现一次的数
// [2,2,1] → 1
int result = 0;
for (int n : nums) result ^= n;
// 2^2^1 = 0^1 = 1 ✅

// 用途：不用临时变量交换两数
a ^= b;
b ^= a;
a ^= b;
```

### 移位运算
```cpp
n >> 1   // 非负整数除以2
n << 1   // 非负整数乘以2
n >> k   // 除以2^k
n << k   // 乘以2^k

// 注意：
// 1. 负数右移在 C++ 中是实现定义行为，刷题里尽量只对非负数这样写。
// 2. 左移可能溢出，尤其是 int 接近上界时。

// 用途：二分查找中点
int mid = left + ((right - left) >> 1);
```

---

## 4. 前缀和

```cpp
// 用途：快速求区间和
// LC560 和为K的子数组

vector<int> nums = {1, 2, 3, 4, 5};
int n = nums.size();

// 建立前缀和
vector<int> prefix(n+1, 0);
for (int i = 0; i < n; i++) {
    prefix[i+1] = prefix[i] + nums[i];
}
// prefix = [0, 1, 3, 6, 10, 15]

// 区间 [l, r] 的和
int sum = prefix[r+1] - prefix[l];
// [1,3] 的和 = prefix[4] - prefix[1] = 10 - 1 = 9 ✅
```

### 二维前缀和
```cpp
// 用途：快速求矩阵区间和
vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1]
                     - prefix[i-1][j-1] + grid[i-1][j-1];

// 子矩阵 (r1,c1) 到 (r2,c2) 的和
int sum = prefix[r2+1][c2+1] - prefix[r1][c2+1]
        - prefix[r2+1][c1] + prefix[r1][c1];
```

---

## 5. 差分数组

```cpp
// 用途：区间批量加减
// LC1109 航班预订统计

vector<int> diff(n+1, 0);

// 区间 [l, r] 加 val（O(1)）
diff[l] += val;
diff[r+1] -= val;

// 还原数组（O(n)）
vector<int> result(n, 0);
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += diff[i];
    result[i] = sum;
}

// 追踪：n=5，区间[1,3]加2，区间[2,4]加3
// diff: [0, 2, 3, 0, -3, -2]
// 还原前 n 个位置: [0, 2, 5, 5, 3]
//
// 说明：这里用的是 0-indexed 区间。
// 如果题目给的是 1-indexed 区间，先统一转换成 0-indexed，或者把 diff 开成 n+2。
```

---

## 6. 双指针

### 对撞指针
```cpp
// 用途：有序数组找两数之和
// LC167

int l = 0, r = n-1;
while (l < r) {
    int sum = nums[l] + nums[r];
    if (sum == target) return {l, r};
    else if (sum < target) l++;
    else r--;
}
```

### 快慢指针
```cpp
// 用途1：找链表中点
ListNode* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow 停在中点

// 用途2：判断链表是否有环
// LC141
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;  // 相遇说明有环
}
return false;
```

### 滑动窗口
```cpp
// 用途：最长/最短子串
// LC3 最长无重复子串

unordered_map<char, int> window;
int left = 0, ans = 0;

for (int right = 0; right < s.size(); right++) {
    window[s[right]]++;              // 加入右边

    while (window[s[right]] > 1) {  // 窗口不合法
        window[s[left]]--;           // 移出左边
        left++;
    }
    ans = max(ans, right - left + 1); // 更新答案
}
```

---

## 7. 二分查找

### 标准模板（找精确值）
```cpp
// LC704
int left = 0, right = n-1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid+1;
    else right = mid-1;
}
return -1;
```

### 左边界（找第一个>=target的位置）
```cpp
// LC35 搜索插入位置
int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) left = mid+1;
    else right = mid;
}
return left;

// [1,3,5,6], target=5 → 2
// [1,3,5,6], target=4 → 2（插入位置）
```

### 右边界（找最后一个<=target的位置）
```cpp
int left = 0, right = n-1;
while (left < right) {
    int mid = left + (right - left + 1) / 2;  // 注意+1防死循环
    if (nums[mid] > target) right = mid-1;
    else left = mid;
}
return left;
```

---

## 8. 哈希技巧

```cpp
// 计数
unordered_map<int,int> freq;
for (int n : nums) freq[n]++;

// 判断存在
freq.count(key)   // 存在返回1，不存在返回0
freq.find(key) != freq.end()  // 同上

// 遍历
for (auto& [key, val] : freq) {
    cout << key << " " << val;
}

// 用途：LC49 字母异位词分组
// 把排序后的字符串作为key
unordered_map<string, vector<string>> groups;
for (string& s : strs) {
    string key = s;
    sort(key.begin(), key.end());
    groups[key].push_back(s);
}
```

---

## 9. 优先队列

```cpp
// 最大堆（默认）
priority_queue<int> maxHeap;
maxHeap.push(3);
maxHeap.top();   // 3（最大值）
maxHeap.pop();

// 最小堆
priority_queue<int, vector<int>, greater<int>> minHeap;

// 用途：LC215 第K大元素
// 维护大小为K的最小堆
priority_queue<int, vector<int>, greater<int>> pq;
for (int n : nums) {
    pq.push(n);
    if (pq.size() > k) pq.pop();  // 超过K个就弹出最小的
}
return pq.top();  // 堆顶就是第K大

// 自定义排序（按第一个元素排序）
auto cmp = [](vector<int>& a, vector<int>& b) {
    return a[0] > b[0];  // 最小堆
};
priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
```

---

## 10. 排序技巧

```cpp
// 自定义排序
// 按绝对值排序
sort(nums.begin(), nums.end(), [](int a, int b){
    return abs(a) < abs(b);
});

// 二维数组按第一个元素排，相同则按第二个
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
});

// 用途：LC56 合并区间
sort(intervals.begin(), intervals.end());
vector<vector<int>> result;
for (auto& interval : intervals) {
    if (result.empty() || result.back()[1] < interval[0]) {
        result.push_back(interval);  // 不重叠，直接加
    } else {
        result.back()[1] = max(result.back()[1], interval[1]);  // 合并
    }
}
```

---

## 11. 数学技巧

```cpp
// 防溢出（二分查找中点）
int mid = left + (right - left) / 2;
// 不用 (left+right)/2，可能溢出

// 向上取整
int ceil = (n + k - 1) / k;
// n=7, k=3: (7+2)/3 = 3 ✅

// 用途：LC29 两数相除
// 不能用乘除，用位移代替
while (dividend >= divisor) {
    int temp = divisor, multiple = 1;
    while (dividend >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
    }
    dividend -= temp;
    result += multiple;
}
```

---

## 12. 单调栈

```cpp
// 用途：找每个元素右边第一个更大的元素
// LC739 每日温度

vector<int> result(n, 0);
stack<int> st;  // 存下标

for (int i = 0; i < n; i++) {
    while (!st.empty() && temps[st.top()] < temps[i]) {
        int idx = st.top(); st.pop();
        result[idx] = i - idx;  // 距离
    }
    st.push(i);
}

// 追踪：[73,74,75,71,69,72,76,73]
// i=0: st=[0]
// i=1: 74>73，弹出0，result[0]=1，st=[1]
// i=2: 75>74，弹出1，result[1]=1，st=[2]
// ...
```

---

## 优先级总结

```
🔴 必须熟练（几乎每场必考）：
   前缀和、双指针、滑动窗口、二分模板

🟠 高频出现：
   哈希操作、优先队列、字符操作

🟡 偶尔用到：
   位运算、差分数组、单调栈、排序技巧
```

这些技巧不需要死记，**做题时遇到了回来查**，做多了自然就记住了 👍
