/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {

  // new Promise((resolve, reject) => {}) 创建一个 Promise 对象
  // resolve(value) 表示成功，reject(error) 表示失败
  // 对应 C++ 里的 future/promise，但更常用
  return new Promise((resolve, reject) => {

    // 边界条件：空数组直接 resolve
    if (functions.length === 0) {
      resolve([]);
      return;  // return 是为了终止函数，不继续往下执行
    }

    // 存放所有结果，fill(null) 先占位
    const res = new Array(functions.length).fill(null);

    // 记录已完成的 Promise 数量，用 let 因为会被重新赋值
    let resolvedCount = 0;

    // forEach 是数组的遍历方法，回调函数接收两个参数：
    // fn 是当前元素，idx 是当前下标
    // 对应 C++ 的 for (int i = 0; i < v.size(); i++)
    // async 关键字让回调函数内部可以使用 await
    functions.forEach(async (fn, idx) => {

      // try/catch 捕获异常，对应 C++ 的 try/catch
      try {

        // await 等待 Promise 完成，拿到结果
        // fn() 调用传入的函数，返回一个 Promise
        // await 会暂停当前 async 函数，直到 Promise resolve
        const val = await fn();

        // 把结果存到对应位置，保证顺序正确
        res[idx] = val;

        // ++ 递增，记录完成数量
        resolvedCount++;

        // 所有 Promise 都完成了，resolve 整个结果数组
        if (resolvedCount === functions.length) {
          resolve(res);
        }

      } catch (err) {
        // 任何一个 Promise 失败，直接 reject
        // 和 Promise.all 的行为一致：一个失败全部失败
        reject(err);
      }
    });
  });
};

// 测试
const promise = promiseAll([
  () => new Promise(res => res(42)),   // 箭头函数返回一个 Promise，resolve(42)
  () => new Promise(res => res(100)),  // resolve(100)
]);
promise.then(console.log); // [42, 100]