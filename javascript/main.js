const solution = require('./leetcode/regularExpressionMatching10DP');

const testCases = [
    { test: ['a', ''], expected: false },
    { test: ['aa', 'aa'], expected: true },
    { test: ['aa', 'a.'], expected: true },
    { test: ['aa', '..'], expected: true },
    { test: ['aa', 'a*'], expected: true },
    { test: ['aaa', 'a*a'], expected: true },
    { test: ['aa', 'a'], expected: false },
    { test: ['ab', '.*'], expected: true },
    { test: ['ab', '.*c'], expected: false },
    { test: ['ab', 'c.*'], expected: false },
    { test: ['ab', 'a.*c.*b'], expected: false },
    { test: ['acb', 'a.*c.*b'], expected: true },
    { test: ['ab', 'a.*.*b'], expected: true },
    { test: ['aab', 'c*a*b'], expected: true },
    { test: ['aa', 'ba*a*'], expected: false },
    { test: ['baa', 'ba*a*c*'], expected: true },
    { test: ['aa', 'aa*a*c*'], expected: true },
    { test: ['mississippi', 'mis*is*p*.'], expected: false },
];
testCases.forEach((testCase, testNo) => {
    const { test, expected } = testCase;
    const result = solution(...test);
    console.log(
      `test #${testNo}:\t${result === expected ? 'pass' : `fail, expected <${expected}> but result is <${result}>`}`
    );
});
