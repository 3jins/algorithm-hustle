// 20:24 ~ 20:32, 21:10 ~ 22:22
// 우릴 속였어. 이건 문자열 파싱 문제가 아니라 DFS잖아!
// 22:40? ~ 00:20, 이후로 한참
//

module.exports = (str, regex) => {
  const parseRegex = (regex) => {
    const parsed = [];
    const regexLen = regex.length;
    let charIdx = 0;
    while (charIdx < regexLen) {
      if (charIdx === regexLen - 1 || regex[charIdx + 1] !== '*') {
        parsed.push(regex[charIdx]);
        charIdx += 1;
      } else {
        parsed.push([regex[charIdx], regex[charIdx + 1]].join(''));
        charIdx += 2;
      }
    }
    return parsed;
  };

  const isSame = (ch, pattern) => {
    if (pattern === '.') return true;
    else return ch === pattern;
  };

  const isPatternsRemained = (patternIdx) => {
    let i = 0;
    while (patternIdx + i < patterns.length) {
      if (!patterns[patternIdx + i].endsWith('*')) return true;
      i += 1;
    }
    return false;
  };

  const isPositiveEnd = (ch, pattern, patternIdx) => (
    ch === undefined && pattern === undefined
    || ch === undefined && !isPatternsRemained(patternIdx)
  );
  const isNegativeEnd = (ch, pattern, patternIdx) => (
    (pattern === undefined && ch !== undefined)
    || (ch === undefined && !isPositiveEnd(ch, pattern, patternIdx))
  );

  const compare = (chIdx, patternIdx, test) => {
    let isMatched = false;
    let isUnmatched = false;
    while (true) {
      const ch = chars[chIdx];
      const pattern = patterns[patternIdx];
      // console.log(test, chIdx, patternIdx, ch, pattern);
      if (isPositiveEnd(ch, pattern, patternIdx)) isMatched = true;
      if (isNegativeEnd(ch, pattern, patternIdx)) isUnmatched = true;
      if (isMatched) return true;
      if (isUnmatched) return false;

      if (pattern.endsWith('*')) {
        // if (isNegativeEnd(ch, pattern, patternIdx)) return false;
        if (!isSame(ch, pattern[0])) { // cannot continue
          patternIdx += 1;
        } else {
          if (compare(chIdx + 1, patternIdx, test + 1)) { // continue
            isMatched = true;
          } else {
            isUnmatched = true;
          }
          if (compare(chIdx, patternIdx + 1, test + 1)) { // escape
            isMatched = true;
          } else {
            isUnmatched = true;
          }
        }
      } else if (isSame(ch, pattern)) {
        if (isNegativeEnd(ch, pattern, patternIdx)) isUnmatched = true;
        chIdx += 1;
        patternIdx += 1;
      } else {
        isUnmatched = true;
      }
    }
  };

  const chars = str.split('');
  const patterns = parseRegex(regex);

  return compare(0, 0, 0);
};
