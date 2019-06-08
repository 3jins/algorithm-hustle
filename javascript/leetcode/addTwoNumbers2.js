const makeNumberFromLinkedList = (linkedList) => {
  const numList = [];
  while (linkedList !== null) {
    numList.push(linkedList.val);
    linkedList = linkedList.next;
  }
  return Number(numList.reverse().join(''));
};

const makeLinkedListFromArray = arr => arr
  .reverse()
  .reduce((linkedList, digit) => ({val: Number(digit), next: linkedList}), null);

const addTwoNumbers = (l1, l2) => {
  let sumList = [];
  let overflow = 0;
  while(l1 !== null || l2 !== null) {
    const sum = (l1 === null ? 0 : l1.val) + (l2 === null ? 0 : l2.val);
    sumList.push((sum + overflow) % 10);
    overflow = Math.floor((sum + overflow) / 10);
    if (l1 !== null) l1 = l1.next;
    if (l2 !== null) l2 = l2.next;
  }
  if (overflow > 0) sumList.push(overflow);
  return makeLinkedListFromArray(sumList);
};

module.exports = { addTwoNumbers, makeLinkedListFromArray, makeNumberFromLinkedList };
