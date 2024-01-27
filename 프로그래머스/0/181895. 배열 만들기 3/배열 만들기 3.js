function solution(arr, [r1,r2]) {
    return [...arr.slice(r1[0],r1[1]+1), ...arr.slice(r2[0],r2[1]+1)];
}