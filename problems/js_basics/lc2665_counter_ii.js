/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let createCount = init;
  return {
    increment: () => ++createCount,
    reset:  () => {
      createCount = init;
      return createCount;
    },
    decrement:  function() {
      return --createCount;
    },
  };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
