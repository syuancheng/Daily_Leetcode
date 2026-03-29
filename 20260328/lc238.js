/**
 * @param {number[]} nums
 * @return {number[]}
 */
// var 是 LeetCode 模板写法，实际项目用 const
// function(nums) 是匿名函数，赋值给变量 productExceptSelf
var productExceptSelf = function (nums) {

  // nums.length 是数组长度属性，不需要加 ()
  // 对应 C++ 的 nums.size()
  const n = nums.length;

  // new Array(n) 创建长度为 n 的空数组
  // 用 let 因为后面不需要重新赋值，其实用 const 也可以
  // 数组内容会变，但数组引用不变，const 完全没问题
  const ans = new Array(n);

  // 第一个元素左边没有元素，乘积初始化为 1
  ans[0] = 1;

  // let 声明循环变量 i，i++ 是 i = i + 1 的简写
  for (let i = 1; i < n; i++) {
    // [] 通过下标访问数组元素，和 C++ 一样
    ans[i] = ans[i - 1] * nums[i - 1];
  }

  // let 因为 r 会被重新赋值
  let r = 1;

  // j-- 是从右往左遍历，j >= 0 是终止条件
  for (let j = n - 1; j >= 0; j--) {

    // *= 是复合赋值运算符，ans[j] = ans[j] * r 的简写
    ans[j] *= r;

    // r 滚动记录右侧乘积，先更新 ans[j] 再更新 r
    // 顺序不能颠倒，否则 ans[j] 会把自身也乘进去
    r *= nums[j];
  }

  // 返回结果数组
  return ans;
};

console.log(productExceptSelf([1, 2, 3, 4]));     // [24, 12, 8, 6]
console.log(productExceptSelf([-1, 1, 0, -3, 3])); // [0, 0, 9, 0, 0]