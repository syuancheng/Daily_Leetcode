// var  → 不要用，是历史遗留写法，LeetCode 模板里有但实际项目不用

// const → 优先用，只要这个变量不需要重新赋值
const n = nums.length;   // 不会变，用 const
const arr = new Array(n) // 数组引用不会变，用 const
const idx = ch => ...    // 函数不会变，用 const

// let → 只有需要重新赋值时才用
let ans = 0;     // 后面 ans = Math.max(...) 会重新赋值，用 let
let left = 0;    // 后面 left++ 会重新赋值，用 let
let tmp = "";    // 后面 tmp = tmp.slice(...) 会重新赋值，用 let
```

---

### 一句话总结
```
var   → 不用
const → 默认用这个
let   → 需要重新赋值时才换成 let

