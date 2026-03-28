/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  const n = nums.length;

  let ans = new Array(n);
  ans[0] = 1;
  for (let i = 1; i < n; i++) {
    ans[i] = ans[i - 1] * nums[i - 1];
  }

  let r = 1;
  for (let j = n - 1; j >= 0; j--) {
    ans[j] = ans[j] * r;

    r *= nums[j];
  }
  return ans;
};
