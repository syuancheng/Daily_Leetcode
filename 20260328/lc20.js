/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const sk = [];

  const map = new Map([
    [')', '('],
    [']', '['],
    ['}', '{'],
  ]);

  for (const c of s) {
    if (c === '(' || c === '[' || c === '{') {
      sk.push(c);
    } else {
      if (sk.pop() !== map.get(c)) {
        return false;
      }
    }
  }

  return sk.length === 0;
};
