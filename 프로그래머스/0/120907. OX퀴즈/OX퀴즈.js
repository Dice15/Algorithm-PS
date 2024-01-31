function solution(quiz, a, b, c) {
    return quiz.map(q=>([a,b,c]=q.match(/\-?\d+/g), (q.match(/\s-\s/g)?.length ? +a - +b: +a + +b) === +c ? 'O' : 'X'))
}