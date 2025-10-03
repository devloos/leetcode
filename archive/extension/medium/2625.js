/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
  if (n === 0) {
    return arr;
  }

  const answer = [];

  arr.forEach((el) => {
    if (n > 0 && Array.isArray(el)) {
      answer.push(...flat(el, n - 1));
    } else {
      answer.push(el);
    }
  });

  return answer;
};
