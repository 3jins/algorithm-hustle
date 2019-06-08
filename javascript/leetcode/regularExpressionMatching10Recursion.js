const isMatch = (str, pattern) => {
  if (pattern === '') return str === '';
  const compareFirst = str !== '' && pattern[0] === '.' || str[0] === pattern[0];

  if (pattern.length > 1 && pattern[1] === '*') {
    return isMatch(str, pattern.slice(2))
      || (compareFirst && isMatch(str.slice(1), pattern));
  } else {
    return compareFirst && isMatch(str.slice(1), pattern.slice(1));
  }
};

module.exports = isMatch;
