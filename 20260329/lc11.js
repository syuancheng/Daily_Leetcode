/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let ans = 0,
    n = height.length;
  if (n < 2) {
    return ans;
  }

  let l = 0,
    r = n - 1;
  while (l < r) {
    let area = (r - l) * Math.min(height[l], height[r]);
    ans = Math.max(ans, area);
    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }
  return ans;
};
