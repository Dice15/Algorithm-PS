function solution(str, n) {
    return str.match(new RegExp(`.{1,${n}}`, 'g'))
}