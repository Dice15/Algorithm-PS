function solution(a, b) {
    return Math.max(parseInt(a.toString()+b.toString()), parseInt(b.toString()+a.toString()));
}