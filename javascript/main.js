const _ = require('lodash');
const { addTwoNumbers: solution, makeLinkedListFromArray, makeNumberFromLinkedList } = require('./leetcode/addTwoNumbers2');

const testCases = [
  {
    test: [makeLinkedListFromArray([2, 4, 3]), makeLinkedListFromArray([5, 6, 4])],
    expected: {
      val: 7, next: {
        val: 0, next: {
          val: 8, next: null,
        }
      }
    },
  },
  {
    test: [makeLinkedListFromArray([3, 1]), makeLinkedListFromArray([0, 9, 1])],
    expected: {
      val: 3, next: {
        val: 0, next: {
          val: 2, next: null,
        }
      }
    },
  },
  {
    test: [makeLinkedListFromArray([1]), makeLinkedListFromArray([9, 9])],
    expected: {
      val: 0, next: {
        val: 0, next: {
          val: 1, next: null,
        }
      }
    },
  },
];
testCases.forEach((testCase, testNo) => {
  const { test, expected } = testCase;
  const result = solution(...test);
  console.log(
    // `test #${testNo}:\t${_.isEqual(result, expected) ? 'pass' : `fail, expected <${expected}> but result is <${result}>`}`
    `test #${testNo}:\t${_.isEqual(result, expected) ? 'pass' : `fail, expected <${makeNumberFromLinkedList(expected)}> but result is <${makeNumberFromLinkedList(result)}>`}`
  );
});
