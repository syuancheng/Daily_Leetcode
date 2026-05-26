const { rejects } = require('node:assert');
const { resolve } = require('node:dns');

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function (promise1, promise2) {
  return (await promise1) + (await promise2);
};

var addTwoPromises1 = async function (promise1, promise2) {
  return await Promise.all([promise1, promise2]).then(([a, b]) => a + b);
};

var addTwoPromises2 = async function (promise1, promise2) {
  const [a, b] = await Promise.all([promise1, promise2]);
  return a + b;
};

var addTwoPromises3 = async function (promise1, promise2) {
  return new Promise((promise1, promise2) => {
    Promise.all([promise1, promise2]).then(([a, b]) => resolve(a + b));
  }).catch(reject);
};
/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
