function solution(str) {
    return str.match(/[^abc]+/g)||["EMPTY"]
}