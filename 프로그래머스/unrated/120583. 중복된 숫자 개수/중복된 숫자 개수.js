function solution(array, n) {
    return array.reduce((cnt, val)=>cnt+Number(val==n),0);
}