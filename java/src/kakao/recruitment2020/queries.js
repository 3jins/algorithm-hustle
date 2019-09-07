// 18:40 ~ 19:00
// 맞췄는지 틀렸는지 모름. 근데 설마 정규식 쓴 건데 맞췄겠어...
const solution = (words, queries) => queries.map(query => words.reduce((word, cnt) => {
  const re = new RegExp(query.replace(/\?/g, '.'));
  if (query.length === word.length && re.test(word)) {
    return cnt + 1;
  }
  return cnt;
}, 0));

solution(['frodo', 'front', 'frost', 'frozen', 'frame', 'kakao'], ['fro??', '????o', 'fr???', 'fro???', 'pro?']);
