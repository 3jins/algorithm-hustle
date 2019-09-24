const _ = require('lodash');
const { solution } = require('./programmers/level2/makingBigNumber');

const testCases = [
  {
    params: ['1924', 2],
    expected: '94',
  },
  {
    params: ['1231234', 3],
    expected: '3234',
  },
  {
    params: ['4177252841', 4],
    expected: '775841',
  },
  {
    params: ['1911', 3],
    expected: '9',
  },
  {
    params: [new Array(1000000).fill('9').join(''), 999999],
    expected: '9',
  }
];
testCases.forEach((testCase, testNo) => {
  const { params, expected } = testCase;
  const result = solution(...params);
  const isPass = _.isEqual(result, expected);
  const color = isPass ? '\x1b[32m%s\x1b[0m' : '\x1b[31m%s\x1b[0m'
  console.log(color, `test #${testNo}:\t${isPass ? 'PASS' : 'FAIL'}`);
  console.log(`  params: ${params.join(', ')}`);
  console.log(`  result: ${result}`);
  if (!isPass) {
    console.log(`  expected <${expected}> but result is <${result}>`);
  }
});
