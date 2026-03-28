// @ts-check

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const map = new Map();

  for (let i = 0; i < nums.length; i++) {
    const complement = target - nums[i];

    // map.has(key)：检查 key 是否存在，返回 boolean
    if (map.has(complement)) {
      // map.get(key)：取出对应的 value
      // 这里返回数组字面量，[] 是 JS 创建数组的方式
      return [map.get(complement), i];
    }
    map.set(nums[i], i);
  }
  return [];
};
