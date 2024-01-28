function solution(arr) {
    return (arr = arr.slice(arr.indexOf(2), arr.lastIndexOf(2) + 1)).length ? arr : [-1];
}