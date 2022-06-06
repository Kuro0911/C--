// memoization recursive approach

const howSum = (target, a, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === 0) return [];
  if (target < 0) return null;
  for (let num of a) {
    const rem = target - num;
    const res = howSum(rem, a, memo);
    if (res !== null) {
      memo[target] = [...res, num];
      return memo[target];
    }
  }
  memo[target] = null;
  return null;
};

const bestSum = (target, a, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === 0) return [];
  if (target < 0) return null;
  let best = null;
  for (let nums of a) {
    const rem = target - nums;
    const res = bestSum(rem, a, memo);
    if (res !== null) {
      const comb = [...res, nums];
      if (best === null || comb.length < best.length) {
        best = comb;
      }
    }
  }
  memo[target] = best;
  return memo[target];
};

const CanConstruct = (target, words, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === "") {
    return true;
  }
  for (let word of words) {
    if (target.indexOf(word) === 0) {
      const suf = target.slice(word.length);
      if (CanConstruct(suf, words, memo) === true) {
        memo[target] = true;
        return memo[target];
      }
    }
  }
  memo[target] = false;
  return memo[target];
};

const CountConstruct = (target, words, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === "") return 1;
  let tot = 0;
  for (let word of words) {
    if (target.indexOf(word) === 0) {
      const suf = target.slice(word.length);
      const numWays = CountConstruct(suf, words, memo);
      tot += numWays;
    }
  }
  memo[target] = tot;
  return memo[target];
};

const AllConstruct = (target, words, memo = {}) => {
  const res = [];
  if (target in memo) return memo[target];
  if (target === "") return [[]];
  for (let word of words) {
    if (target.indexOf(word) === 0) {
      const suf = target.slice(word.length);
      const ans = AllConstruct(suf, words);
      const tot = ans.map((way) => [word, ...way]);
      res.push(...tot);
    }
  }
  memo[target] = res;
  return memo[target];
};

// tabulation : iterative approach
